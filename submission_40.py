import numpy as np
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap

X = np.random.random((10000, 2))
y = (X[:, 0] + X[:, 1] + np.random.randn(10000) * 0.1< 1).astype(int)
X_train, y_train, X_test, y_test = X[0:9000], y[0:9000], X[9001:len(X)], y[9001:len(y)]
model = Sequential()
model.add(Dense(1, input_dim=2, activation='sigmoid'))
model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])
_ = model.fit(X_train, y_train, epochs=30, verbose=1)
x0_min, x0_max, x1_min, x1_max = X_test[:, 0].min() - 0.1, X_test[:, 0].max() + 0.2, X_test[:, 1].min() - 0.1, X_test[:, 1].max() + 0.2
X_0_mesh, X_1_mesh = np.meshgrid(np.arange(x0_min, x0_max, 0.1), np.arange(x1_min, x1_max, 0.1))
y_pred = model.predict(np.array([X_0_mesh.ravel(), X_1_mesh.ravel()]).T)
y_pred = y_pred.reshape(X_0_mesh.shape)
cmap = ListedColormap(['red', 'blue'])
plt.figure(figsize=(6, 6), facecolor='white')
plt.contourf(X_0_mesh, X_1_mesh, y_pred, alpha=0.3, cmap=cmap, levels=1)
plt.scatter(X_test[:1000, 0], X_test[:1000, 1], c=y_test[:1000], cmap=cmap)
plt.plot()
