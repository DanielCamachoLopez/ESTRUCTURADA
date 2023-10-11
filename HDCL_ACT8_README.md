{
  "nbformat": 4,
  "nbformat_minor": 0,
  "metadata": {
    "colab": {
      "provenance": [],
      "authorship_tag": "ABX9TyM0/a82OsvsZfK/fjvhDLew",
      "include_colab_link": true
    },
    "kernelspec": {
      "name": "python3",
      "display_name": "Python 3"
    },
    "language_info": {
      "name": "python"
    }
  },
  "cells": [
    {
      "cell_type": "markdown",
      "metadata": {
        "id": "view-in-github",
        "colab_type": "text"
      },
      "source": [
        "<a href=\"https://colab.research.google.com/github/DanielCamachoLopez/ESTRUCTURADA/blob/main/HDCL_ACT8_README.md\" target=\"_parent\"><img src=\"https://colab.research.google.com/assets/colab-badge.svg\" alt=\"Open In Colab\"/></a>"
      ]
    },
    {
      "cell_type": "markdown",
      "source": [
        "##ACTIVIDAD 8\n",
        "\n",
        "Nombre: Hector Daniel Camacho Lopez\n",
        "\n",
        "Matricula:372239\n",
        "\n",
        "Grupo: 432\n",
        "\n",
        "Fecha: Ensenada, Baja California a 08 Octubre del 2023\n",
        "\n"
      ],
      "metadata": {
        "id": "bLSOuA8NZQxq"
      }
    },
    {
      "cell_type": "markdown",
      "source": [
        "1.- Programa en python que genere un número entre el 1 y 10 (no visible)  preguntarle al usuario que número cree que generó la computadora, el usuario tendrá 3 oportunidades de adivinar.  Decir si adivino o si falló en sus 3 intentos."
      ],
      "metadata": {
        "id": "vKnnMngOZteK"
      }
    },
    {
      "cell_type": "code",
      "source": [
        "def valida_num(rangoi, rangof, n):\n",
        "  z = 1\n",
        "  if n > rangof:\n",
        "    print(\"El numero sobrepasa el limite del rango\")\n",
        "    z = 0\n",
        "  if n < rangoi:\n",
        "    print(\"El numero es muy pequeño para entrar en el rango\")\n",
        "    z = 0\n",
        "  return z"
      ],
      "metadata": {
        "id": "-xgs4grcaSud"
      },
      "execution_count": null,
      "outputs": []
    },
    {
      "cell_type": "code",
      "execution_count": null,
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "V5MWCbueZMpn",
        "outputId": "77ec511b-f47e-40ed-bd16-7e5523f4423b"
      },
      "outputs": [
        {
          "name": "stdout",
          "output_type": "stream",
          "text": [
            "PRESIONA\n",
            "1 - JUGAR\n",
            "0 - SALIR\n",
            "Que eliges hacer? 1\n",
            "JUEGO INICIADO\n",
            "Se genero un numero aleatorio entre el 1 y el 10, que numero crees que se genero? 4\n",
            "Ese no era el numero, tienes 2 intentos mas\n",
            "Que numero crees que se genero del 1 al 10? 5\n",
            "Ese no era el numero, te queda una sola oportunidad\n",
            "Que numero crees que se genero del 1 al 10? 8\n",
            "Lo siento, ese no era el numero y se te acabaron las oportunidades.\n",
            "EL NUMERO ERA: 10\n",
            "PRESIONA\n",
            "1 - JUGAR\n",
            "0 - SALIR\n",
            "Que eliges hacer? 1\n",
            "JUEGO INICIADO\n",
            "Se genero un numero aleatorio entre el 1 y el 10, que numero crees que se genero? 3\n",
            "Ese no era el numero, tienes 2 intentos mas\n",
            "Que numero crees que se genero del 1 al 10? 2\n",
            "Ese no era el numero, te queda una sola oportunidad\n",
            "Que numero crees que se genero del 1 al 10? 1\n",
            "Lo siento, ese no era el numero y se te acabaron las oportunidades.\n",
            "EL NUMERO ERA: 4\n",
            "PRESIONA\n",
            "1 - JUGAR\n",
            "0 - SALIR\n",
            "ERROR, digita solo numeros ENTEROS, no letras ni caracteres especiales\n",
            "Que eliges hacer? 0\n"
          ]
        }
      ],
      "source": [
        "\n",
        "try:\n",
        "  import random\n",
        "\n",
        "  ciclo = 1\n",
        "  while ciclo == 1:\n",
        "    print(\"PRESIONA\")\n",
        "    print(\"1 - JUGAR\")\n",
        "    print(\"0 - SALIR\")\n",
        "    opc = int(input(\"Que eliges hacer? \"))\n",
        "    if opc == 0:\n",
        "      break\n",
        "    num = random.randint(1, 10)\n",
        "    print(\"JUEGO INICIADO\")\n",
        "    rangoi = 1\n",
        "    rangof = 10\n",
        "    n = int(input(\"Se genero un numero aleatorio entre el 1 y el 10, que numero crees que se genero? \"))\n",
        "    z = valida_num(rangoi, rangof, n)\n",
        "\n",
        "    if z == 0:\n",
        "      break\n",
        "\n",
        "    if n == num:\n",
        "        print(\"FELICIDADES, adivinaste el numero al primer intento\")\n",
        "    else:\n",
        "      print(\"Ese no era el numero, tienes 2 intentos mas\")\n",
        "      n = int(input(\"Que numero crees que se genero del 1 al 10? \"))\n",
        "      if n == num:\n",
        "        print(\"FELICIDADES, adivinaste al segundo intento\")\n",
        "      else:\n",
        "        print(\"Ese no era el numero, te queda una sola oportunidad\")\n",
        "        n = int(input(\"Que numero crees que se genero del 1 al 10? \"))\n",
        "        if n == num:\n",
        "          print(\"FELICIDADES, adivinaste el numero al tercer intento\")\n",
        "        else:\n",
        "          print(\"Lo siento, ese no era el numero y se te acabaron las oportunidades.\")\n",
        "\n",
        "    print(f\"EL NUMERO ERA: {num}\")\n",
        "\n",
        "except:\n",
        "  print(\"ERROR, digita solo numeros ENTEROS, no letras ni caracteres especiales\")\n",
        "\n",
        "\n",
        "\n",
        "\n"
      ]
    },
    {
      "cell_type": "markdown",
      "source": [
        "2.- El juego Busca Número muestra una lista de 10 numeros, sin mostrar su contenido.\n",
        "Al usuario se le muestra un número que se generó aleatoriamente y el usuario tendrá 3 intentos de adivinar en qué índice del arreglo se encuentra.\n",
        "El usuario recibirá un mensaje que diga GANASTE, PERDISTE, TIENES UN NUEVO INTENTO.\n",
        "El usuario podrá jugar cuantas veces lo desee."
      ],
      "metadata": {
        "id": "67qhrMFE_p4i"
      }
    },
    {
      "cell_type": "markdown",
      "source": [
        "##FORMA 1"
      ],
      "metadata": {
        "id": "gjGFuu7b7v8e"
      }
    },
    {
      "cell_type": "code",
      "source": [
        "def forma1():\n",
        "    lista = []\n",
        "    import random\n",
        "    numero = list(range(0,10))\n",
        "    random.shuffle(numero)\n",
        "    lista = numero[:10]\n",
        "    alea = random.randint(0,10)\n",
        "    num = random.randint(1,10)\n",
        "\n",
        "    print(f\"Numero tomado de la lista aleatoriamente: {lista[alea]}\")\n",
        "\n",
        "    bien = 1\n",
        "    mal = 2\n",
        "    while(mal >= 0):\n",
        "        numero = int(input(\"Digita el indice en donde crees que esta el numero mostrado: \"))\n",
        "        if(numero == num):\n",
        "            print(f\"FELICIDADES, ganaste en el intento {bien}\")\n",
        "            return 1\n",
        "            break\n",
        "        else:\n",
        "            if mal != 0:\n",
        "                print(f\"Te quedan {mal} intentos\")\n",
        "            else:\n",
        "                print(f\"PERDISTE, ya no te quedan intentos\")\n",
        "                return 0\n",
        "        mal = mal - 1\n",
        "        bien = bien + 1"
      ],
      "metadata": {
        "id": "y45in-1E7ykx"
      },
      "execution_count": 115,
      "outputs": []
    },
    {
      "cell_type": "code",
      "source": [
        "ganar = 0\n",
        "perder = 0\n",
        "decision = 1\n",
        "while(decision == 1):\n",
        "    part = forma1()\n",
        "    if part == 1:\n",
        "        ganar = ganar + 1\n",
        "    if part == 0:\n",
        "        perder = perder + 1\n",
        "\n",
        "    print(\"PRESIONA:\")\n",
        "    print(\"1 - CONTINUAR \")\n",
        "    print(\"0 - SALIR \")\n",
        "    decision = int(input(\"Digita tu decision aqui: \"))\n",
        "\n",
        "print(f\"Ganaste {ganar} partidas en total\")\n",
        "print(f\"Perdiste {perder} partidas en total\")"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/",
          "height": 0
        },
        "id": "IJ-Wsivz8cti",
        "outputId": "0c733059-fc49-416f-aa73-e8b714b7d3c6"
      },
      "execution_count": 116,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "Numero tomado de la lista aleatoriamente: 3\n",
            "Digita el indice en donde crees que esta el numero mostrado: 5\n",
            "Te quedan 2 intentos\n",
            "Digita el indice en donde crees que esta el numero mostrado: 4\n",
            "Te quedan 1 intentos\n",
            "Digita el indice en donde crees que esta el numero mostrado: 3\n",
            "PERDISTE, ya no te quedan intentos\n",
            "PRESIONA:\n",
            "1 - CONTINUAR \n",
            "0 - SALIR \n",
            "Digita tu decision aqui: 0\n",
            "Ganaste 0 partidas en total\n",
            "Perdiste 1 partidas en total\n"
          ]
        }
      ]
    },
    {
      "cell_type": "markdown",
      "source": [
        "##FORMA 2"
      ],
      "metadata": {
        "id": "sfrL03Yvcost"
      }
    },
    {
      "cell_type": "code",
      "source": [
        "def forma2():\n",
        "    lista = []\n",
        "    while(len(lista) < 10):\n",
        "        num = random.randint(1,10)\n",
        "        if num not in lista:\n",
        "            lista.append(num)\n",
        "    alea = random.randint(1,10)\n",
        "    print(f\"Numero tomado de la lista aleatoriamente: {lista[alea]}\")\n",
        "\n",
        "    bien = 1\n",
        "    mal = 2\n",
        "    while(mal >= 0):\n",
        "        numero = int(input(\"Digita el indice en donde crees que esta el numero mostrado: \"))\n",
        "        if(numero == num):\n",
        "            print(f\"FELICIDADES, ganaste en el intento {bien}\")\n",
        "            return 1\n",
        "            break\n",
        "        else:\n",
        "            if mal != 0:\n",
        "                print(f\"Te quedan {mal} intentos\")\n",
        "            else:\n",
        "                print(f\"PERDISTE, ya no te quedan intentos\")\n",
        "                return 0\n",
        "        mal = mal - 1\n",
        "        bien = bien + 1"
      ],
      "metadata": {
        "id": "ZWxrBF0Tcsyc"
      },
      "execution_count": 117,
      "outputs": []
    },
    {
      "cell_type": "code",
      "source": [
        "ganar = 0\n",
        "perder = 0\n",
        "decision = 1\n",
        "while(decision == 1):\n",
        "    partida = forma2()\n",
        "    if partida == 1:\n",
        "        ganar = ganar + 1\n",
        "    if partida == 0:\n",
        "        perder = perder + 1\n",
        "\n",
        "    print(\"PRESIONA:\")\n",
        "    print(\"1 - CONTINUAR \")\n",
        "    print(\"0 - SALIR \")\n",
        "    decision = int(input(\"Digita tu decision aqui: \"))\n",
        "\n",
        "print(f\"Ganaste {ganar} partidas en total\")\n",
        "print(f\"Perdiste {perder} partidas en total\")"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/",
          "height": 0
        },
        "id": "h4NOksuGcwVH",
        "outputId": "93b6d3d4-8dc6-400a-a8c9-8d307f4a4116"
      },
      "execution_count": 119,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "Numero tomado de la lista aleatoriamente: 5\n",
            "Digita el indice en donde crees que esta el numero mostrado: 5\n",
            "FELICIDADES, ganaste en el intento 1\n",
            "PRESIONA:\n",
            "1 - CONTINUAR \n",
            "0 - SALIR \n",
            "Digita tu decision aqui: 0\n",
            "Ganaste 1 partidas en total\n",
            "Perdiste 0 partidas en total\n"
          ]
        }
      ]
    },
    {
      "cell_type": "markdown",
      "source": [
        "##FORMA 3"
      ],
      "metadata": {
        "id": "c7R3Uj-lzcoM"
      }
    },
    {
      "cell_type": "code",
      "source": [
        "def forma3():\n",
        "    lista = []\n",
        "    lista = range(0,10)\n",
        "    lista = random.sample(lista,10)\n",
        "    aleat = random.randint(1,10)\n",
        "\n",
        "    num = random.randint(1,10)\n",
        "    print(f\"Numero tomado de la lista aleatoriamente: {lista[aleat]}\")\n",
        "    bueno = 1\n",
        "    malo = 2\n",
        "    while(malo >= 0):\n",
        "        numero = int(input(\"Digita el indice en donde crees que esta el numero mostrado: \"))\n",
        "        if(numero == num):\n",
        "            print(f\"FELICIDADES, ganaste en en intento {bueno}\")\n",
        "            return 1\n",
        "            break\n",
        "        else:\n",
        "            if malo != 0:\n",
        "                print(f\"Te quedan {malo} intentos\")\n",
        "            else:\n",
        "                print(f\"PERDISTE, ya no te quedan intentos\")\n",
        "                return 0\n",
        "        malo = malo - 1\n",
        "        bueno = bueno + 1"
      ],
      "metadata": {
        "id": "FYavdPoxziQ_"
      },
      "execution_count": 125,
      "outputs": []
    },
    {
      "cell_type": "code",
      "source": [
        "deci = 1\n",
        "ganado = 0\n",
        "perdido = 0\n",
        "while(deci == 1):\n",
        "    partid = forma3()\n",
        "    if partid == 1:\n",
        "        ganado = ganado + 1\n",
        "    if partid == 0:\n",
        "        perdido = perdido + 1\n",
        "    print(\"PRESIONA:\")\n",
        "    print(\"1 - CONTINUAR \")\n",
        "    print(\"0 - SALIR \")\n",
        "    deci = int(input(\"Digita tu decision aqui: \"))\n",
        "\n",
        "print(f\"Ganaste {ganado} partidas en total\")\n",
        "print(f\"Perdiste {perdido} partidas en total\")"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/",
          "height": 0
        },
        "id": "u-ctwTbUzmav",
        "outputId": "fcf5163b-5da8-417d-8b35-5bb718801fcb"
      },
      "execution_count": 126,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "Numero tomado de la lista aleatoriamente: 4\n",
            "Digita el indice en donde crees que esta el numero mostrado: 5\n",
            "Te quedan 2 intentos\n",
            "Digita el indice en donde crees que esta el numero mostrado: 4\n",
            "FELICIDADES, ganaste en en intento 2\n",
            "PRESIONA:\n",
            "1 - CONTINUAR \n",
            "0 - SALIR \n",
            "Digita tu decision aqui: 0\n",
            "Ganaste 1 partidas en total\n",
            "Perdiste 0 partidas en total\n"
          ]
        }
      ]
    }
  ]
}