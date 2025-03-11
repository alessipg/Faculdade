import socket
import ipaddress

LOCALHOST = "127.0.0.1"
PORT = 8080

# Banco de dados fictício de usuários e senhas
usuarios = {
    "admin": "1234",
    "user": "senha123"
}

# Função para calcular endereços IPv4
def calcularIPv4(endereco):
    rede = ipaddress.IPv4Network(endereco, strict=False)
    totalEnderecos = max(0, rede.num_addresses - 2)
    if totalEnderecos > 0:
        enderecoUtilInicial = str(next(rede.hosts()))
        enderecoUtilFinal = str(ipaddress.IPv4Address(int(rede.network_address) + rede.num_addresses - 2))
    else:
        enderecoUtilInicial = "Sem endereços úteis"
        enderecoUtilFinal = "Sem endereços úteis"
    return totalEnderecos, enderecoUtilInicial, enderecoUtilFinal

# Função para calcular endereços IPv6
def calcularIPv6(endereco):
    rede = ipaddress.IPv6Network(endereco, strict=False)
    totalEnderecos = rede.num_addresses
    print(rede.hosts())
    if totalEnderecos > 0:
        enderecoUtilInicial = str(next(rede.hosts()))
        enderecoUtilFinal = str(ipaddress.IPv6Address(int(rede.network_address) + rede.num_addresses - 1))
    else:
        enderecoUtilInicial = "Sem endereços úteis"
        enderecoUtilFinal = "Sem endereços úteis"
    return totalEnderecos, enderecoUtilInicial, enderecoUtilFinal

# Cria o socket e inicia o servidor
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind((LOCALHOST, PORT))
server.listen() 
print("Servidor inicializado")
print("Esperando dados do cliente...")

# Aceita a conexão do cliente
client_connection, client_address = server.accept()
print("Cliente conectado:", client_address)

# Autenticação
credenciais = client_connection.recv(1024).decode()
try:
    login, senha = credenciais.split(';', 1)
    if usuarios.get(login) == senha:
        client_connection.send("Autenticado".encode())
        print(f"Cliente autenticado: {login}")
    else:
        client_connection.send("Falha na autenticação".encode())
        print(f"Tentativa de login inválida: {login}")
        client_connection.close()
        exit()
except Exception as e:
    client_connection.send("Erro no formato das credenciais".encode())
    print(f"Erro ao processar credenciais: {e}")
    client_connection.close()
    exit()

# Loop principal para processar dados do cliente
try:
    while True:
        data = client_connection.recv(1024)
        if not data:
            break
        msg = data.decode()
        if msg == 'exit':
            print("Encerrando conexão com o cliente.")
            break
        print(f"Dados recebidos: {msg}")

        # Processa a mensagem recebida
        try:
            ipType, ipAddress = msg.split(';', 1)
            ipType = int(ipType)
            if ipType == 1:
                result = calcularIPv4(ipAddress)
            elif ipType == 2:
                result = calcularIPv6(ipAddress)
            else:
                result = "Tipo de IP inválido."
        except Exception as e:
            result = f"Erro ao processar IP: {e}"

        # Envia o resultado ao cliente
        client_connection.send(str(result).encode())
finally:
    # Encerra a conexão
    client_connection.close()
