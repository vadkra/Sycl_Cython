from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

ext_modules = cythonize(
                Extension('cy.cymodule.interface',
                sources=['cy/cymodule/interface.pyx'],
                include_dirs=['../cpp/build/include/'],
                library_dirs=['../cpp/build/lib/'],
                libraries=['src'],
                language='c++'
               ))

packages = ['cy.cythonmodule']

setup(name='cy',
      packages=packages,
      ext_modules=ext_modules,
      package_data={'cy.cymodule.interface': ['*.so']})
