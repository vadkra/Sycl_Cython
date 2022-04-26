# Sycl_Cython

To execute:

```
mkdir build
cd build
cmake ..
make install
cd ../../py
python setup.py build_ext --inplace install
python try-after-install.py
```

The program should return 0
