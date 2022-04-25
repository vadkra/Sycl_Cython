from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

ext_modules = cythonize(
                Extension('thepackage.cythonmodule.interface',
                sources=['thepackage/cythonmodule/interface.pyx'],
                include_dirs=['../cpp-project/build/include/'],
                library_dirs=['../cpp-project/build/lib/'],
                libraries=['src'],
                language='c++'
               ))

packages = ['thepackage.cythonmodule']

setup(name='thepackage',
      packages=packages,
      ext_modules=ext_modules,
      package_data={'thepackage.cythonmodule.interface': ['*.so']})
