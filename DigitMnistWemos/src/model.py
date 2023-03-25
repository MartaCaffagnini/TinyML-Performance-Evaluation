import numpy as np
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras.layers import Input, Conv2D, MaxPooling2D, Flatten, Dense
from tensorflow.keras.models import Model
from tensorflow.keras.datasets import mnist
from tinymlgen import port


# Load MNIST dataset
(x_train, y_train), (x_test, y_test) = mnist.load_data()

# Normalize pixel values to between 0 and 1
x_train = x_train.astype('float32') / 255.0
x_test = x_test.astype('float32') / 255.0

#x_train = x_train.reshape((len(x_train), 28, 28, 1))
#x_test = x_test.reshape((len(x_test), 28, 28, 1))



# Reshape data to be compatible with CNN input
x_train = np.expand_dims(x_train, axis=-1)
x_test = np.expand_dims(x_test, axis=-1)

# Define model architecture
inputs = Input(shape=(28, 28, 1))
x = Conv2D(26, (3, 3), activation='relu')(inputs)
x = MaxPooling2D((2, 2))(x)
x = Flatten()(x)
x = Dense(10, activation='softmax')(x)
model = Model(inputs=inputs, outputs=x)

# Compile model with categorical cross-entropy loss and accuracy metric
model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])

# Train model
model.fit(x_train, y_train, validation_data=(x_test, y_test), epochs=5)

# Convert model 
c_code = port(model, variable_name='mnist_model', pretty_print=True, optimize=False)
print(c_code)
