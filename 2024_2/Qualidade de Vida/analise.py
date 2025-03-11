import pandas as pd

# Carregar a tabela
tabela = pd.read_csv("respostas.csv")

# Substituir valores na tabela
tabela = tabela.replace({
    'Nada/Muito Ruim': '1',
    'Muito Pouco/Ruim': '2',
    'Médio/Nem Ruim Nem Bom': '3',
    'Muito/Bom': '4',
    'Completamente/Muito Bom': '5'
})

# Remover a coluna "Carimbo de data/hora"
tabela = tabela.drop(columns=["Carimbo de data/hora"])


# Salvar o CSV sem o índice extra
tabela.to_csv("dados.csv",index=False)
