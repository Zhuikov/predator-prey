#include "model.h"
#include <ctime>
#include <cstdlib>

//TODO: использовать список инициализации
Model::Model(Settings *set): field(set->field_height, set->field_length)
{
    this->sett = set;
    //Field created_field(10, 10);
    //this->field = created_field;
    model_day = 0;
    model_time = 0;
    has_changed = false;
}


//TODO: не понятно, зачем этот метод, почему нельзя все это сделать в конструкторе
//а если захочется пересоздать живность, вызвать деструктор для старой модели,
//и конструктором сделать новую
void Model::initializeModel()
{
    this->model_day = 0;
    this->model_time = 0;
    this->has_changed = false;
    
    //Field created_field(sett->field_height, sett->field_length);
    //this->field = created_field;
    srand(time(0));  
    
    deletePredators();
    deletePreys();
    
    //TODO: если это вынести в конструктор, то метод не нужен
    createPredators();
    createPreys();
}

bool Model::isEnd() const
{
    if (units.predators.empty() || units.preys.empty()){
        return true;
    }
    return false;
}

void Model::createPredators()
{
    for(int i = 0; i < sett->num_of_predators; i++) {
        int v = 0;
        int h = 0;
//        while (1 == 1) {
//            i_pred = rand() % sett->field_height;
//            j_pred = rand() % sett->field_length;
//            if (field.isEmpty(i_pred, j_pred)){
//                    break;
//            }
//        }

        do{
            v = rand() % sett->field_height;
            h = rand() % sett->field_length;
        }
        while(field.isEmpty(v, h) == false);

        //TODO: pred --> predator
        Predator *pred = new Predator(v, h, &field, sett->moves_without_meal);
        pred->setUnitsPointer(&units);
        units.predators.push_back(pred);
    }
}

//TODO: это ненужное удалить, но в любом случае можно было использовать foreach синтаксис
void Model::deletePredators()
{
    if (!units.predators.empty()) {
        for (std::vector<Predator*>::const_iterator i = units.predators.begin();
             i != units.predators.end(); ++i) delete *i;
        units.predators.clear();
    }
}

void Model::createPreys()
{
    for(int i = 0; i < sett->num_of_preys; i++) {
        int v = 0;
        int h = 0;
        //TODO: оформить do-while цикл
        while (1 == 1) {
            v = rand() % sett->field_height;
            h = rand() % sett->field_length;
            if (field.isEmpty(v, h)) break;
        }
        //TODO: pr --> prey
        Prey *pr = new Prey(v, h, &field);
        pr->setUnitsPointer(&units);
        units.preys.push_back(pr);
    }
}

//TODO: это ненужное удалить, но в любом случае можно было использовать foreach синтаксис
void Model::deletePreys()
{
    if (!units.preys.empty()) {
        for (std::vector<Prey*>::const_iterator i = units.preys.begin();
             i != units.preys.end(); ++i) delete *i;
        units.preys.clear();
    }
}

void Model::movePreys()
{

    //TODO: этот кусок дублирует такой же в movePredators, лучше вынести в отдельный метод инкрементирования времени модели
    if (!this->has_changed) {
        this->model_time = this->model_time + 1;
        this->has_changed = true;
    }
    else has_changed = false;

    if (this->model_time > 23) {
        this->model_day++;
        this->model_time = 0;
    }

    for(Prey* prey: units.preys){
        if(prey->died == false){
            prey->movePrey();
        }
    }
    //std::vector<Prey*>::iterator last = units.preys.end();
    //for (std::vector<Prey*>::iterator i = units.preys.begin(); i != last; ++i)
    //    if ((*i)->died == false) (*i)->movePrey();

}

void Model::movePredators()
{
    if (!this->has_changed) {
        this->model_time = this->model_time + 1;
        this->has_changed = true;
    }
    else has_changed = false;

    if (this->model_time > 23) {
        this->model_day++;
        this->model_time = 0;
    }

    for(Predator* predator: units.predators){
        if(predator->died == false){
            predator->movePredator();
        }
    }

//    std::vector<Predator*>::iterator last = units.predators.end();
//    for (std::vector<Predator*>::iterator i = units.predators.begin(); i !=last; ++i)
//        if ((*i)->died == false) (*i)->movePredator();
}

//TODO: не говоря о прочем, этот метод и removePreys очень похожи, уверена, что используя наследование от animal, можно попытаться объединить в один полиморфный метод,
//это можно обсудить отдельно после основного и очевидного рефакторинга
void Model::removePredators()
{
    int num_of_died = 0;
    for (std::vector<Predator*>::const_iterator it = units.predators.begin();
         it != units.predators.end(); ++it)
        if ((*it)->died == true) num_of_died++;

    int num_deleted_died = 0;
    while (num_deleted_died < num_of_died) {
        for (std::vector<Predator*>::iterator it = units.predators.begin();
             it != units.predators.end(); ++it) {
            if ((*it)->died == true) {
                delete (*it);
                if ((*it) != units.predators.back()) std::swap((*it), units.predators.back());
                units.predators.pop_back();
                num_deleted_died ++;
                break;
            }
        }
    }
}

void Model::removePreys()
{
    int num_of_died = 0;
    for (std::vector<Prey*>::const_iterator it = units.preys.begin(); it != units.preys.end(); ++it)
        if ((*it)->died == true) num_of_died++;

    int num_deleted_died = 0;
    while (num_deleted_died < num_of_died) {
        for (std::vector<Prey*>::iterator it = units.preys.begin(); it != units.preys.end(); ++it) {
            if ((*it)->died == true) {
                delete (*it);
                if ((*it) != units.preys.back()) std::swap((*it), units.preys.back());
                units.preys.pop_back();
                num_deleted_died ++;
                break;
            }
        }
    }
}

//TODO: здесь просится деструктор
void Model::remove()
{
    removePredators();
    removePreys();
}
