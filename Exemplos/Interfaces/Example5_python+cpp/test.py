#!/usr/bin/env python3
import sys
import os

# Adiciona o diretório de instalação ao path
home = os.environ['HOME']
mypythonpath = os.path.join(home, "posdoc/unicamp/F056/git/Exemplos/Interfaces/Example5_python+cpp/python3")
sys.path.append(mypythonpath)

# Importa o módulo
import MyModule

# Usa as funções
MyModule.my_test("Hello World")

