import socket

SERVER = "127.0.0.1"
PORT = 8080

# Cria o socket
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Conecta ao servidor
client.connect((SERVER, PORT))

# Autenticação
login = input("Digite seu login: ")
senha = input("Digite sua senha: ")
credenciais = f"{login};{senha}"

# Envia credenciais
client.send(credenciais.encode())

# Recebe a resposta do servidor
resposta = client.recv(1024).decode()
if resposta == "Autenticado":
    print("Login bem-sucedido!")
else:
    print("Falha na autenticação. Encerrando conexão.")
    client.close()
    exit()

# Entra em loop principal
while True:
    print("\nEscolha o tipo de IP:")
    print("1. IPv4")
    print("2. IPv6")
    opcao = input("Digite sua escolha (1 ou 2): ")

    if opcao == '1':
        endereco = input("Digite o endereço IPv4 com máscara (exemplo: 192.168.1.10/24): ")
        mensagem = f"1;{endereco}"
    elif opcao == '2':
        endereco = input("Digite o endereço IPv6 com máscara (exemplo: 2001:db8:baba::11/48): ")
        mensagem = f"2;{endereco}"
    else:
        print("Opção inválida. Tente novamente.")
        continue

    # Envia a mensagem ao servidor
    client.send(mensagem.encode())

    # Recebe e exibe a resposta
    resposta = client.recv(1024).decode()
    try:
        qtd_uteis, inicio, final = eval(resposta)  # Decodifica a tupla recebida
        print(f"\nQuantidade de endereços úteis: {qtd_uteis}")
        print(f"Endereço útil inicial: {inicio}")
        print(f"Endereço útil final: {final}\n")
    except Exception as e:
        print(f"Erro ao processar resposta do servidor: {e}")

    # Opção para encerrar
    sair = input("Digite 'exit' para sair ou pressione Enter para continuar: ")
    if sair.lower() == "exit":
        client.send("exit".encode())
        break

# Encerra a conexão
client.close()
