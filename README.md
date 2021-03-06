# :volcano: Volcano Sort
The hottest sorting algorithm around!

![version](https://img.shields.io/badge/version-1.0.4-blue)
![PyPI - Downloads](https://img.shields.io/pypi/dm/VolcanoSort?label=pip%20installs)

### Disclaimer
This algorithm runs in O(n<sup>2</sup>). Please don't use this.

### Motivation
Our professor mentioned volcanoes when discussing sorting algorithms. I realized there wasn't a "Volcano Sort". There shouldn't be, but now there is.

### Methodology
This algorithm first constructs a volcano from the input. Then, the volcano "erupts" and places the numbers in sorted order. 

What does this mean?

Given the following input: [4,8,2,2,1,3,0], Volcano Sort will construct a volcano: [1,2,4,8,3,2,0]. It looks like this:

<img src="https://i.ibb.co/Kjp4ZwT/volcano-diagram.jpg" alt="volcano-diagram" width="400" height="300" border="0">

The volcano will erupt and place numbers in increasing order. 

Output: [0,1,2,2,3,4,8]

## Installation
```bash
pip install VolcanoSort
```

## Usage
```python
from VolcanoSort import volcano

arr = [4, 5, 8, 1, 2, 3, 7, 6, 9]
arr = volcano.sort(arr)
print(arr)
```
```bash
[1, 2, 3, 4, 5, 6, 7, 8, 9]
```


### Future Development
None!
