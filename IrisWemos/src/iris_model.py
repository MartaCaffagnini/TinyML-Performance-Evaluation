#! pip install everywhereml>=0.0.3
from everywhereml.get_started import iris_dataset, iris_classifier
"""
Fit classifier on Iris train dataset and test accuracy on Iris test dataset.
For such a simple dataset, you can expect a score above 0.9
"""
iris_train, iris_test = iris_dataset.split(test_size=0.3)
iris_classifier.fit(iris_train)

print('Classification score on test dataset: %.2f' % iris_classifier.score(iris_test))

"""
Export the classifier to Arduino C++ code.
"""
# return a string with the C++ code
iris_classifier.to_arduino(instance_name='classifier', class_map=iris_dataset.class_map)

