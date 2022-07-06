import csv
import sys

# função que identifica quantas vezes seguidas apareceu um str no dna do indivíduo analisado.
def consecRepeats(str, sequenceReader):
    i = 0
    # usa o while pra saber enquanto é possivel realizar a boolean expression
    while str*(i+1) in sequenceReader:
        # se o i for 0 e existe, aumenta um no i. se for 2 e existir no arquivo, auemnta o i. assim vai.
        i += 1
    return i

# função que checa se cada linha da database é identica ao número de vezes que aparece a coluna no indivíduo analisado.
def match(coluna, dnaSequence, row):
    # para cada string da coluna
    for str in coluna:
        # se o numero da sequencia de dna da coluna não for igual ao número da linha da database, retorna falso
        if dnaSequence[str] != int(row[str]):
            return False
    # se não deu certo.
    return True

def main():

    # Checa se realemnte tem 3 comandos.
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit()

    databaseFile = sys.argv[1]
    # a função with abre o arquivo, mas se der erro ela volta. Assim a gente não se preocupa em fechar no final tbm.
    with open(databaseFile) as database:
        # depois de aberto, transformo em um dicionário a partir da função csv.DictReader
        databaseReader = csv.DictReader(database)
        # eu tbm pego a primeira linha, a qual contem o "nome" de cada coluna de informação em um objeto.
        coluna = databaseReader.fieldnames[1:]

        sequenceFile = sys.argv[2]
        # agora vou abrir a sequencia de DNA de quem estou analisando.
        with open(sequenceFile) as sequence:
            sequenceReader = sequence.read()
            # aqui eu crio um dicionario para armazenar quantas vezes repetiu cada coluna
            dnaSequence = {}
            for str in coluna:
                dnaSequence[str] = consecRepeats(str, sequenceReader)

            # para cada linha na minha data base
            for row in databaseReader:
                # se alinha da database tiver o match entre a coluna e o numero armazenado
                if match(coluna, dnaSequence, row):
                    # printa o nome do cara que foi achado
                    print("{}".format(row['name']))
                    # se não volta tudo
                    return

    # se chegou ate aqui é porque não deu match com a database
    print("No match")

main()