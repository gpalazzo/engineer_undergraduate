import numpy as np
import time
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.metrics import confusion_matrix, classification_report
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier
from sklearn.preprocessing import StandardScaler
import urllib


start_time = time.time()

url = "https://archive.ics.uci.edu/ml/machine-learning-databases/statlog/german/german.data-numeric"
raw_data = urllib.request.urlopen(url)
df = np.genfromtxt(raw_data)
X, y = list(df[:,:-1]), list(df[:,-1:].squeeze())

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.3, random_state = 42, stratify = y)

scaler = StandardScaler()
scaler.fit(X_train)
X_train = scaler.transform(X_train)
X_test = scaler.transform(X_test)


#24 entradas

nn = MLPClassifier(verbose=True,
                   activation='logistic',
                   tol=0.00001,
                   max_iter=500,
                   learning_rate_init = 0.001,
                   hidden_layer_sizes=(49,2),
                   batch_size=5,
                   solver='adam',
                   early_stopping=False)

y_pred = nn.fit(X_train, y_train).predict(X_test)
y_test = np.array(y_test)

prob_test = []
prob_trein = []
prob_array = nn.predict_proba(X_test)

for elem in prob_array:
    if(elem[0] > elem[1]):
        prob_test.append(elem[0])
    else:
        prob_test.append(elem[1])


prob_array = nn.predict_proba(X_train)

for elem in prob_array:
    if(elem[0] > elem[1]):
        prob_trein.append(elem[0])
    else:
        prob_trein.append(elem[1])

print("\nAcurácia do modelo no conjunto de treinamento: {:.2f}%\n".format(nn.score(X_train, y_train)*100))
print("Acurácia do modelo no conjunto de teste: {:.2f}%\n".format(nn.score(X_test, y_test)*100))

cm = confusion_matrix(y_test, y_pred)
print("Matriz de Confusão - Resultados absolutos\n{}".format(cm))
print("\n\n")

print("Relatório de Classificação:\n{}".format(classification_report(y_test, y_pred)))

print("\n\n")
classes = ['Bom Pagador', 'Mau Pagador']
cmap=plt.cm.Blues
plt.imshow(cm, interpolation='nearest', cmap=cmap)
plt.title('Matriz de Confusão')
plt.colorbar()
tick_marks = np.arange(len(classes))
plt.xticks(tick_marks, classes, rotation=45)
plt.yticks(tick_marks, classes)
plt.ylabel('Resultado Esperado')
plt.xlabel('Resultado Obtido')
plt.tight_layout()
plt.show()
print("O algoritmo demorou {} segundos".format(time.time() - start_time))

print("\n\n")
plt.plot(prob_trein)
plt.title('Probabilidade de Acerto em cada Época - Conjunto Treinamento')
plt.ylabel('Probabilidade')
plt.xlabel('Épocas')
plt.show()

print("\n\n")
plt.plot(prob_test)
plt.title('Probabilidade de Acerto em cada Época - Conjunto Teste')
plt.ylabel('Probabilidade')
plt.xlabel('Épocas')
plt.show()

print("\n\n")
plt.plot(nn.loss_curve_)
plt.title("Curva de Erro aplicado a Função Custo")
plt.ylabel('Erro + Função Custo')
plt.xlabel('Épocas')
plt.show()
