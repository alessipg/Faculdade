def ativacao(u):
    return 1 if u >= 0 else 0

def perceptron(x, w, d, alpha=0.01, usaBias=False, bias=1, wBias=0.5, maxEpochs=1000):
    epochs = 0
    while epochs < maxEpochs:
        u = x * w + (bias * wBias if usaBias else 0)
        y = ativacao(u)

        e = d - y
        if e == 0:
            break

        w += alpha * e * x
        if usaBias:
            wBias += alpha * e * bias
        epochs += 1

    if epochs == maxEpochs:
        print("Limite de épocas atingido.")
    
    return epochs, round(w, 4), round(wBias, 4) if usaBias else None


# Simulações 1 a 4 - sem bias
semBias = [
    {"entrada": 1, "peso": 0.5, "saidaEsperada": 0},
    {"entrada": 1, "peso": 0.5, "saidaEsperada": 1},
    {"entrada": 0, "peso": 0.5, "saidaEsperada": 1},
    {"entrada": 0, "peso": 0.5, "saidaEsperada": 0},
]

print("Simulações sem Bias:")
for i, s in enumerate(semBias, 1):
    epocas, wFinal, _ = perceptron(s["entrada"], s["peso"], s["saidaEsperada"])
    print(f"Simulação {i}: Épocas = {epocas}, Peso final = {wFinal}")

# Simulações 5 a 8 - com bias
comBias = [
    {"entrada": 1, "peso": 0.5, "saidaEsperada": 0},
    {"entrada": 1, "peso": 0.5, "saidaEsperada": 1},
    {"entrada": 0, "peso": 0.5, "saidaEsperada": 1},
    {"entrada": 0, "peso": 0.5, "saidaEsperada": 0},
]

print("\nSimulações com Bias:")
for i, s in enumerate(comBias, 5):
    epocas, wFinal, wBiasFinal = perceptron(
        s["entrada"], s["peso"], s["saidaEsperada"], usaBias=True
    )
    print(f"Simulação {i}: Épocas = {epocas}, Peso final = {wFinal}, Peso Bias = {wBiasFinal}")
