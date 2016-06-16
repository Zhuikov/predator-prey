import subprocess


def start_model(mode: object, height: object, width: object, n_preys: object, n_predators: object, seed: object) -> object:
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

class ModelParams:
    mode = "S"
    height = 0
    width = 0
    n_preys = 0
    n_predators = 0
    seed = 0

    def __init__(self, mode, height, width, n_preys, n_predators, seed):
        self.mode = mode
        self.height = height
        self.width = width
        self.n_preys = n_preys
        self.n_predators = n_predators
        self.seed = seed


def f(params):
    return start_model(params.mode, params.height, params.width, params.n_preys, params.n_predators, params.seed)

#def f1(params):
#    return start_model("S", params.height, params.width, params.n_preys, params.n_predators, params.seed)