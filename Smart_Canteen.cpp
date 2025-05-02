#include<iostream>
#include<string>
#include<queue>
using namespace std;
class Order {
    public:
    int token_no;
    string order_type;
    string payment_process;
    int making_time;
    Order(int no,string type,string process,int time){
        token_no=no;
        order_type=type;
        payment_process=process;
        making_time=time;

    }
};

class ManageQueue  {
    private:
    queue<Order> bevageQueue;
    queue<Order> lunchQueue;

    public:
    void addOrder(const Order& order){
        if(order.order_type =="bevage"){
            bevageQueue.push(order);
            cout<<"added token no"<<order.token_no<<"to the bevage session";
        }
            else if(order.order_type=="lunch"){
                lunchQueue.push(order);
                cout<<"added token no"<<order.token_no<<"to the lunch session";

            
        }
        else{
            cout<<"invalid input"<<" ";

        }
    }


void processOrder(const string &counter_type){
    if (counter_type=="bevage"){
        if (bevageQueue.empty()){
            cout<<"No current orders"<<" ";

        }else {
           Order current  =bevageQueue.front();
           bevageQueue.pop();
           cout<<"preparing bevage token no"<<current.token_no<<"Payment:"<<current.payment_process<<" ";


        }
    }
    else if(counter_type=="lunch"){
        if(lunchQueue.empty()){
            cout<<"No  current orders on lunch counter"<<" ";
            
        }else {
            Order current = lunchQueue.front();
            lunchQueue.pop();
            cout<< "processing the token no"<<current.token_no<<"payment:"<<current.payment_process<<" ";


        }

    } else
    { 
        cout<<" invalid input"<<" ";

    }
    
}   

void estimateWaitingTime(const string& counter_type) {
    int totalTime = 0;
    if (counter_type == "Beverage") {
    queue<Order> tempQueue = bevageQueue;
    while (!tempQueue.empty()) {
    totalTime += tempQueue.front().making_time;
    tempQueue.pop();
    }
    cout << "Estimated wait time for Beverage Counter: " << totalTime << "minutes.\n";
    }
     else if (counter_type == "Lunch") {
    queue<Order> tempQueue = lunchQueue;
    while (!tempQueue.empty()) {
    totalTime += tempQueue.front().making_time;
    tempQueue.pop();
    }
    cout << "Estimated wait time for Lunch Counter: " << totalTime << "minutes.\n";
    } 
    else {
    cout << "Invalid counter type.\n";
    }
    }
};

    class CBIT_Canteen {
        private: ManageQueue queue_Manager;   
        int order_Counter;
        public:
       CBIT_Canteen() : order_Counter(0) {}
        void  displayMenu(){
            cout<<"Menu\n";
            cout<<"bevages\n";
            cout<<"ice cream\n";
            cout<<"Cool drinks\n";
            cout<<"chocolets\n";
            cout<<"juices\n";
            cout<<"Tea\n";
            cout<<"Coco cola\n";

        }
        void displayPaymentOptions (const string & order_type)
        {
            cout<<"payment methods for order type"<<order_type<<" ";    
        if (order_type=="bevage") {
            cout<<"1. digital payment";
        }  
        else if(order_type=="lunch"){
            cout<<"1. Cash\n";
            cout<<"2. Card\n";

        } else{
            cout<<"incorrect input"<<" "; 
        }
    }

    string selectPaymentMethod(int choice, const string& itemType) {
        if (itemType == "Bevage") {
            if (choice == 1) return "digital payment\n";
        } else if (itemType == "Lunch") {
            if (choice == 1) return "Cash";
            if (choice == 2) return "Card";
        }
        return "Invalid";
    }
    void takeOrder(int menuChoice, int paymentChoice) {
        string order_type;
        int making_time = 0;

        if (menuChoice == 1) { order_type = "Beverage"; making_time = 5; }
        else if (menuChoice == 2) { order_type = "Beverage"; making_time = 4; }
        else if (menuChoice == 3) { order_type = "Beverage"; making_time = 3; }
        else if (menuChoice == 4) { order_type = "Lunch"; making_time = 10; }
        else if (menuChoice == 5) { order_type = "Lunch"; making_time = 15; }
        else if (menuChoice == 6) { order_type = "Lunch"; making_time = 12; }
        else {
            cout << "Invalid menu choice.\n";
            return;
        }
        
        string payment_process = selectPaymentMethod(paymentChoice, order_type);
        if (payment_process == "Invalid") {
            cout << "Invalid payment choice.\n";
            return;
        }
        order_Counter++;
        Order newOrder(order_Counter, order_type, payment_process, making_time);
        queue_Manager.addOrder(newOrder);
    }
    void processOrders(const string& counter_type) {
        queue_Manager.processOrder(counter_type);
    }

    void estimateWaitingTimes(const string& counter_type) {
        queue_Manager.estimateWaitingTime(counter_type);
    }
};
int main() {
    CBIT_Canteen canteen_point;

    cout << "Welcome to the Smart Canteen Ordering System!\n";
    canteen_point.displayMenu();

    cout << "\nBeverage Payment Options:\n";
    canteen_point.displayPaymentOptions("Beverage");

    cout << "\nLunch Payment Options:\n";
    canteen_point.displayPaymentOptions("Lunch");

    cout << "\nTaking Orders:\n";
    canteen_point.takeOrder(1, 1); 
    canteen_point.takeOrder(5, 2); 
    cout << "\nEstimating Wait Times:\n";
    canteen_point.estimateWaitingTimes("Beverage");
    canteen_point.estimateWaitingTimes("Lunch");

    cout << "\nProcessing Orders:\n";
    canteen_point.processOrders("Beverage");
    canteen_point.processOrders("Lunch");

    return 0;
}

