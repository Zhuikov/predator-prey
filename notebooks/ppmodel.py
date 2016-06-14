import subprocess


def start_model(mode, height, width, n_preys, n_predators, seed):
    height = str(height)
    width = str(width)
    n_preys = str(n_preys)
    n_predators = str(n_predators)
    seed = str(seed)

    model = subprocess.run(["pp-model", mode, width, height, n_predators, n_preys, seed], stdout=subprocess.PIPE)
    return_code = model.returncode

    if mode == "L":

        filename = '%sx%s_%s_%s_%s.csv' % (width, height, n_predators, n_preys, seed)
        f = open(filename, 'r')

        predators = []
        preys = []

        for line in f:
            data = line.split(',')
            predators.append(int(data[1]))
            preys.append(int(data[2]))
        return predators, preys, return_code

    else:
        return return_code