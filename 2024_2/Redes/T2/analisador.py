import pandas as pd

# Carrega os dados
tabela = pd.read_csv("trabalho2.csv")

# Filtra pacotes TCP e ICMP
fluxos = tabela.loc[tabela['Protocol'].isin(['TCP', 'ICMP'])].copy().drop(['No.', 'Info'], axis=1)

# Ordena pacotes para garantir um fluxo contínuo
fluxos = fluxos.sort_values(['Protocol', 'Source', 'Destination', 'Length', 'Time'])

# Calcula os intervalos de tempo entre pacotes (Gap)
fluxos['Gap'] = fluxos.groupby(['Protocol', 'Source', 'Destination', 'Length'])['Time'].diff().fillna(0)

# Estatísticas por fluxo
estatisticas = fluxos.groupby(['Protocol', 'Source', 'Destination', 'Length']).agg(
    tamanho_medio=('Length', 'mean'),                                   # Tamanho médio dos pacotes
    tamanho_min=('Length', 'min'),                                      # Tamanho mínimo dos pacotes
    tamanho_max=('Length', 'max'),                                      # Tamanho máximo dos pacotes
    soma_pacotes=('Length', 'sum'),                                     # Soma do tamanho de todos os pacotes
    duracao_fluxo=('Time', lambda x: x.max() - x.min()),                # Duração do fluxo
    media_gap=('Gap', 'mean'),                                          # Média do intervalo de tempo de geração
    min_gap=('Gap', lambda x: x[x > 0].min() if (x > 0).any() else 0),  # Intervalo mínimo
    max_gap=('Gap', 'max')                                              # Intervalo máximo
).reset_index()
estatisticas.drop('Length', axis = 1, inplace=True)
# Calcula taxa média de geração de pacotes (bits por segundo)
estatisticas['taxa_media_bps'] = (estatisticas['soma_pacotes'] * 8) / estatisticas['duracao_fluxo'].replace(0, 1)
estatisticas = estatisticas.rename(columns={
    'Protocol': 'Protocolo',
    'Source': 'Origem',
    'Destination': 'Destino',
    'tamanho_medio': 'Tamanho Médio',
    'tamanho_min': 'Tamanho Mínimo',
    'tamanho_max': 'Tamanho Máximo',
    'soma_pacotes': 'Soma Tamanho',
    'duracao_fluxo': 'Duração Fluxo',
    'media_gap': 'Média Intervalo',
    'min_gap': 'Intervalo Mínimo',
    'max_gap': 'Intervalo Máximo',
    'taxa_media_bps': 'Taxa Média bps'
})

# Salva os dados processados
fluxos.to_csv("fluxos_detalhados.csv", index=False)
estatisticas.to_csv("estatisticas_fluxos.csv", index=False)

print("Arquivos salvos: fluxos_detalhados.csv e estatisticas_fluxos.csv")
