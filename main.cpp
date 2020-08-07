#include <iostream>

struct node
{
    char * problem;
    node * next;
    node()
    {
        problem = "bolsheNet";
        next = nullptr;
    }
    node(char * prblm, node * nxt)
    {
        problem = prblm;
        next = nxt;
    }
};

class Human
{
public:
    Human(int ht, int wt, char sexy, char * nm)
    {
        age = 0;
        height = ht;
        weight = wt;
        sex = sexy;
        name = nm;
        happyLevel = 10;
        sportLevel = 1;
        problems = nullptr;
        if (sex == 'M')
            brainLevel = 35;
        else
            brainLevel = 40;
    }
    Human(int ag, int ht, int wt, char sexy, int brlvl, int hpylvl, int sprtlvl, char * nm)
    {
        age = ag;
        height = ht;
        weight = wt;
        sex = sexy;
        name = nm;
        brainLevel = brlvl;
        happyLevel = hpylvl;
        sportLevel = sprtlvl;
        problems = nullptr;
    }

    void PrintAllParams() const
    {
        std::cout << name <<std::endl;
        std::cout << "AGE - " << age <<std::endl;
        std::cout << "HEIGHT - " << height << std::endl;
        std::cout << "WEIGHT - " << weight << std::endl;
        std::cout << "SEX - " << sex << std::endl;
        std::cout << "HAPPYNESS - " << happyLevel << std::endl;
        std::cout << "HEALTH - " << sportLevel << std::endl;
        std::cout << "INTELLECT - " << brainLevel << '\n' << std::endl;
        if(areYouDead())
            std::cout << name << " DEAD" << '\n' << std::endl;
    }
    void runAround()
    {
        brainLevel = brainLevel - 1;
        sportLevel = sportLevel + 3;
        std::cout << name << " run a mile" << '\n' << std::endl;
        if(areYouDead())
            std::cout << name << " Dead" << '\n' << std::endl;
    }
    void readBook()
    {
        brainLevel = brainLevel + 1;
        sportLevel = sportLevel -1;
        std::cout << name << " read a book" << '\n' << std::endl;
        if(areYouDead())
            std::cout << name << " Dead" << '\n' << std::endl;
    }

    void watchFilm()
    {
        happyLevel = happyLevel + 3;
        sportLevel = sportLevel -1;
        brainLevel = brainLevel -1;
        std::cout << name << " watched a film" << '\n' << std::endl;
        if(areYouDead())
            std::cout << name << " Dead" << '\n' << std::endl;
    }

    void addNewProblem(char * newPr)
    {
        if(problems == nullptr)
            problems = new node(newPr, nullptr);
        else
        {
            node * temp = problems;
            while(temp -> next != nullptr)
            {
                temp = temp -> next;
            }
            temp -> next = new node(newPr, nullptr);
        }
    }
    void printProblems()
    {
        node * tosee = problems;


        std::cout << name << " problems:" << std::endl;
        while(tosee != nullptr)
        {

            std::cout << tosee -> problem << std::endl;
            tosee = tosee -> next;
        }
        std::cout << '\n' << std::endl;
    }

    void deleteProblem(char * delProblem)
    {

        node * killp;
        if(problems -> problem == delProblem)
        {
            killp = problems;
            std::cout << "problem " << delProblem << " deleted" << '\n' << std::endl;
            problems = problems -> next;
            delete killp;
            return;
        }
        while (problems != nullptr)
        {
            if (problems -> problem == delProblem)
            {
                std::cout << "problem " << delProblem << " deleted" << '\n' << std::endl;
                killp = problems;
                problems = problems -> next;
                delete killp;
            }
            else
                problems = problems -> next;

        }
    }

private:
    int brainLevel;
    int age;
    int height;
    int weight;
    int happyLevel;
    int sportLevel;
    char sex;
    char * name;
    node * problems;


    bool areYouDead() const
    {
        return happyLevel <= 0 || sportLevel <= 0 || brainLevel <= 0;
    }

};

int main() {
    Human Nina(12, 140, 50, 'M', 58, 55, 22, "Nina");
    Human Leonid(52, 4, 'M', "Leonid");
    Human Marina(45,3,'F', "Marina");
    Leonid.PrintAllParams();
    Leonid.runAround();
    Leonid.readBook();
    Leonid.watchFilm();
    Leonid.PrintAllParams();

    Marina.addNewProblem("Headache");
    Marina.addNewProblem("Stomachache");


    Nina.addNewProblem("TooBusy");
    Nina.addNewProblem("WantSleep");
    Nina.addNewProblem("Drank");


    Nina.deleteProblem("TooBusy");
    Nina.deleteProblem("WantSleep");

    Nina.addNewProblem("Study");

    Nina.printProblems();

    return 0;
}
