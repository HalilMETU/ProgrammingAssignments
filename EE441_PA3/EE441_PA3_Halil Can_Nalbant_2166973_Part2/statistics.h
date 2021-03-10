//class that is used to record the performance parameters of the sorting algorithms
//with method such as increment moves/comparisons, start/stop timer, display stats
class stats{
private:
    int comps;//number of comparisons
    int moves;//number of moves
    double time;//elapsed time
    double Start;
    double Stop;
public:
    stats(){
    comps=0;
    moves=0;
    time=0;
    Start=0;
    Stop=0;
    }

    void display(int replay)const
    {
        /*
        cout<<"Number of comparisons: "<<comps<<"  ";
        cout<<"Number of moves: "<<moves<<"  ";
        cout<<"Elapsed time: "<<time<<endl;
        */
        cout<<comps/replay<<"             "<<moves/replay<<"        "<<time/replay<<endl;
    }

    //Increment Comparisons
    void Icomps(){
        stop();
        comps++;
        start();
        }

    //Increment moves
    void Imoves(){
        stop();
        moves++;
        start();
        }


    //Reset
    void Reset(){
        comps=0;
        moves=0;
        time=0;
        Start=0;
        Stop=0;
        }
    //start timer
    void start(){Start=double(clock());}
    //stop timer
    void stop(){
        Stop=double(clock());
        time=(Stop-Start)+time;
        Start=0;
        Stop=0;
    }



};
