from distutils.core import setup, Extension
# Define o módulo
module1 = Extension('MyModule',
                    sources = ['testmodule.cc'])
setup(name = 'MyPackage',
      version = '1.0',
      description = 'This is a demo package',
      ext_modules = [module1])
