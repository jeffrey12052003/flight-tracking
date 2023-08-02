#include<bits/stdc++.h>
using std::string;
using std::cin;

using namespace std;
int n = 7;
char arr[20][100] = {"Delhi", "Cambodia", "Paris", "Moscow", "Tokyo", "New York", "London"};

typedef struct nodes {
   int dest;
   int cost;
}node;

class Graph {
   int n;
   list<node> *adjList;
   private:
      void showList(int src, list<node> lt) {
         list<node> :: iterator i;
         node tempNode;

         for(i = lt.begin(); i != lt.end(); i++) {
            tempNode = *i;
            cout << "(" << arr[src] << ")---("<<arr[tempNode.dest] << "|"<<tempNode.cost<<")";
            cout<<" %% ";
         }
         cout<<endl<<endl;
      }
   public:
      Graph() {
         n = 0;
      }

      Graph(int nodeCount) {
         n = nodeCount;
         adjList = new list<node>[n];
      }

      void addEdge(int source, int dest, int cost) {
         node newNode;
         newNode.dest = dest;
         newNode.cost = cost;
         adjList[source].push_back(newNode);
      }

      void displayEdges() {
         for(int i = 0; i<n; i++) {
            list<node> tempList = adjList[i];
            showList(i, tempList);
         }
      }

      friend void dijkstra(Graph g, int *dist, int *prev, int start);
};

void dijkstra(Graph g, int *dist, int *prev, int start) {
   int n = g.n;

   for(int u = 0; u<n; u++) {
      dist[u] = 9999;   //set as infinity
      prev[u] = -1;    //undefined previous
   }

   dist[start] = 0;   //distance of start is 0
   set<int> S;       //create empty set S
   list<int> Q;

   for(int u = 0; u<n; u++) {
      Q.push_back(u);    //add each node into queue
   }

   while(!Q.empty()) {
      list<int> :: iterator i;
      i = min_element(Q.begin(), Q.end());
      int u = *i; //the minimum element from queue
      Q.remove(u);
      S.insert(u); //add u in the set
      list<node> :: iterator it;

      for(it = g.adjList[u].begin(); it != g.adjList[u].end();it++) {
         if((dist[u]+(it->cost)) < dist[it->dest]) { //relax (u,v)
            dist[it->dest] = (dist[u]+(it->cost));
            prev[it->dest] = u;
         }
      }
   }
}

static int src_index = 0;
static int dest_index = 0;
static int start_index = 0;
static int end_index = 0;
static int d_index = 0;
static int category_index = 0;
static int pay_index = 0;
static int card_index = 0;
static int ticket_index = 0;
static int seat_index = 0;
static int fare = 0;

std::string book_no;
std::string book_class;
// To get the length of string array
// Base class
class Booking_option {
public:
	// pure virtual function providing interface framework.
	virtual void menu() = 0;
	
protected:
	
	
};

class Book_ticket {
public:
	// pure virtual function providing interface framework.
	virtual void book() = 0;

	std::string from[10];
	std::string to[10];
	std::string f_name[10];
	std::string l_name[10];
	std::string date[10];
	std::string t_class[10];
	std::string payment[10];
	std::string card_no[10];
	std::string t_no[10];
	std::string seat_no[10];
	std::string fare_amt[10];


};

// Derived classes
class Showops : public Booking_option {
public:
	void menu() {
		cout << "\n-------Main Menu--------\n\n";
		cout << "1. Book a ticket\n";
		cout << "2. Cancel a ticket\n";
		cout << "3. View a ticket\n";
		cout << "4. Modify Ticket\n";
		cout << "5. Exit";
	}

};

// Derived classes
class Flight_ticket: public Book_ticket {
public:

	int from_opt;
	int to_opt;
	int class_opt;
	int card_opt;

	
	void book() {

		// Get the from station detail
		do {
			cout << "\nFrom City:\n";
			cout << "1. Delhi\n";
			cout << "2. Cambodia\n";
			cout << "3. Paris\n";
			cout << "4. Moscow\n";
			cout << "5. Tokyo\n";
			cout << "6. New York\n";
			cout << "7. London\n";

			cout << "\nEnter your choice : ";
			cin >> from_opt;

		

				switch (from_opt) {
				case 1:
					from[src_index++] = "Delhi";
					break;
				case 2:
					from[src_index++] = "Cambodia";
					break;
				case 3:
					from[src_index++] = "Paris";
					break;
				case 4:
					from[src_index++] = "Moscow";
					break;
				case 5:
					from[src_index++] = "Tokyo";
					break;
				case 6:
					from[src_index++] = "New York";
					break;
				case 7:
					from[src_index++] = "Londom";
					break;
				default:
					cout << "Invalid option";
					break;
				}
			} while (from_opt > 7);

			// Get the to-station detail
			do {
				    cout << "\nDestination City:\n";
					cout << "1. Delhi\n";
					cout << "2. Cambodia\n";
					cout << "3. Paris\n";
					cout << "4. Moscow\n";
					cout << "5. Tokyo\n";
					cout << "6. New York\n";
					cout << "7. London\n";

				cout << "\nEnter your choice : ";
				cin >> to_opt;
                if (from_opt == to_opt){
                    cout<<"\n\nSource city is same as destination city\n please use other modes of transport";
                }
				switch (to_opt) {
				case 1:
					to[dest_index++] = "Delhi";
					break;
				case 2:
					to[dest_index++] = "Cambodia";
					break;
				case 3:
					to[dest_index++] = "Paris";
					break;
				case 4:
					to[dest_index++] = "Moscow";
					break;
				case 5:
					to[dest_index++] = "Tokyo";
					break;
				case 6:
					to[dest_index++] = "New York";
					break;
				case 7:
					to[dest_index++] = "London";
					break;
				default:
					cout << "Invalid option";
					break;
				}
			} while (to_opt > 7);


			// Get the First Name
			cout << "Enter your first name : ";
			cin.ignore();
			//std::getline(std::cin, f_name[start_index++]);
			cin >> f_name[start_index++];

			// Get the Last Name
			cout << "Enter your last name : ";
			cin.ignore();
			//std::getline(std::cin, l_name[end_index++]);
			cin >> l_name[end_index++];
			

			//Get the date of ticket
			cout << "Date of flight : (DD-MM--YYYY) : ";
			cin.ignore();
			cin >> date[d_index++];

			//Get the type of class
			do {
				cout << "\nTicket class:\n";
				cout << "1. Economy\n";
				cout << "2. Business\n";

				cout << "\nEnter your choice : ";
				cin >> class_opt;

			
				switch (class_opt) {
				case 1:
					t_class[category_index++] = "Economy";
					book_class = "Economy";
					break;
				case 2:
					t_class[category_index++] = "Business";
					book_class = "Business";
					break;
				default:
					cout << "Invalid option";
					break;
				}
			} while (class_opt > 2);

			//Get the payment option
			do {
				cout << "\nPayment Option:\n";
				cout << "1. Credit card\n";
				cout << "2. Debit card\n";
				cout << "3. Master card\n";
				
				cout << "\nEnter your choice : ";
				cin >> card_opt;


				switch (card_opt) {
				case 1:
					payment[pay_index++] = "Credit card";
					break;
				case 2:
					payment[pay_index++] = "Debit card";
					break;
				case 3:
					payment[pay_index++] = "Master card";
					break;
				default:
					cout << "Invalid option";
					break;
				}
			} while (card_opt > 3);


			//Get the card number
			cout << "Enter card number (16-digit) : ";
			cin.ignore();
			cin >> card_no[card_index++];


			//Generate random seat number
			srand(time(0));

			long int k = 0;
			k = 10 + (rand() % 90);

			seat_no[seat_index++] = std::to_string(k);

			//Generate random ticket number
			srand(time(0));

			long int j = 0;
			j = 10000000 + (rand() % 90000000);

			t_no[ticket_index++] = std::to_string(j);
	
			book_no = std::to_string(j);

			if (book_class == "Economy") {
				fare_amt[fare++] = "680 $";
			}
			else {
				fare_amt[fare++] = "1200 $";
			}
	}
};

// Derived classes
class CancelTicket {
public:
	std::string enteredNumber;
	int counter = 0;

	void cancelDetail(Flight_ticket &Flight_ticketObject) {
		cout << "\nEnter your ticket number : ";
		cin >> enteredNumber;

		for (int i = 0; i < ticket_index; i++) {

			if (Flight_ticketObject.t_no[i] == enteredNumber) {
				counter = 1;

				Flight_ticketObject.f_name[i] = "";
				Flight_ticketObject.l_name[i] = "";
				Flight_ticketObject.from[i] = "";
				Flight_ticketObject.to[i] = "";
				Flight_ticketObject.date[i] = "";
				Flight_ticketObject.t_no[i] = "";
				Flight_ticketObject.t_class[i] = "";
				Flight_ticketObject.card_no[i] = "";

				break;
			}
		}

		if (counter == 0) {
			cout << "\nTicket number not valid! Try again.\n";
		}
		else {
			cout << "\nTicket canceled.\n";
			counter = 0;
		}
	}

};

// Derived classes
class ViewTicket {
public:
	std::string enteredNumber;
	int counter = 0;
	
	void viewDetail(Flight_ticket &Flight_ticketObject) {
		cout << "\nEnter your ticket number : ";
		cin >> enteredNumber;

		for (int i = 0 ; i < ticket_index ; i++) {

			if (Flight_ticketObject.t_no[i] == enteredNumber) {
				counter = 1;
				cout << "\n\n------------------Your Ticket------------------";
				cout << "\n-----------------------------------------------";
				cout << "\n\t\t---Air Canada---";
				cout << "\n   Your Name : " << Flight_ticketObject.f_name[i] << " " << Flight_ticketObject.l_name[i];
				cout << "\n   From : " << Flight_ticketObject.from[i];
				cout << "\t\tTo : " << Flight_ticketObject.to[i];
				cout << "\n   Date : " << Flight_ticketObject.date[i] << "\t" << "Seat number : B" << Flight_ticketObject.seat_no[i]; 
				cout << "\n   Ticket Class : " << Flight_ticketObject.t_class[i];
				cout << "\n   Ticket number : " << Flight_ticketObject.t_no[i] << "\tFare : " << Flight_ticketObject.fare_amt[i];

				cout << "\n-----------------------------------------------\n";
				cout << "-----------------------------------------------\n";
				break;
			}
		}

		if (counter == 0) {
			cout << "\nTicket number not valid! Try again.\n";
		}
		else {
			counter = 0;
		}
	}
};

// Derived classes
class ModifyTicket{
public:
	std::string enteredNumber;
	int counter = 0;
    int des, src;
	void modifyTicket(Flight_ticket &Flight_ticketObject) {
		cout << "\nEnter your ticket number : ";
		cin >> enteredNumber;

		for (int i = 0; i < ticket_index; i++) {

			if (Flight_ticketObject.t_no[i] == enteredNumber) {

				counter = 1;
				cout << "\n\n------------------Your Ticket------------------";
				cout << "\n-----------------------------------------------";
				cout << "\n\t\t---Air Canada---";
				cout << "\n   Your Name : " << Flight_ticketObject.f_name[i] << " " << Flight_ticketObject.l_name[i];
				cout << "\n   From : " << Flight_ticketObject.from[i];
				cout << "\t\tTo : " << Flight_ticketObject.to[i];
				cout << "\n   Date : " << Flight_ticketObject.date[i] << "\t" << "Seat number : B" << Flight_ticketObject.seat_no[i];
				cout << "\n   Ticket Class : " << Flight_ticketObject.t_class[i];
				cout << "\n   Ticket number : " << Flight_ticketObject.t_no[i] << "\tFare : " << Flight_ticketObject.fare_amt[i];

				cout << "\n-----------------------------------------------\n";


				//Get the new detail for the ticket

				int from_opt;
				int to_opt;
				int class_opt;
				int card_opt;


				do {
					cout << "\nFrom City:\n";
					cout << "1. Delhi\n";
					cout << "2. Cambodia\n";
					cout << "3. Paris\n";
					cout << "4. Moscow\n";
					cout << "5. Tokyo\n";
					cout << "6. New York\n";
					cout << "7. London\n";

					cout << "\nEnter your choice : ";
					cin >> from_opt;
                    src=from_opt;
					
					switch (from_opt) {
					case 1:
						Flight_ticketObject.from[i] = "Delhi";
						break;
					case 2:
						Flight_ticketObject.from[i] = "Cambodia";
						break;
					case 3:
						Flight_ticketObject.from[i] = "Paris";
						break;
					case 4:
						Flight_ticketObject.from[i] = "Moscow";
						break;
					case 5:
						Flight_ticketObject.from[i] = "Tokyo";
						break;
					case 6:
						Flight_ticketObject.from[i] = "New York";
						break;
					case 7:
						Flight_ticketObject.from[i] = "London";
						break;
					default:
						cout << "Invalid option";
						break;
					}
				} while (from_opt > 7);

				// Get the to-station detail
				do {
					cout << "\nDestination City:\n";
					cout << "1. Delhi\n";
					cout << "2. Cambodia\n";
					cout << "3. Paris\n";
					cout << "4. Moscow\n";
					cout << "5. Tokyo\n";
					cout << "6. New York\n";
					cout << "7. London\n";
					cout << "\nEnter your choice : ";
					cin >> to_opt;
					des=to_opt;

					switch (to_opt) {
					case 1:
						Flight_ticketObject.to[i] = "Delhi";
						break;
					case 2:
						Flight_ticketObject.to[i] = "Cambodia";
						break;
					case 3:
						Flight_ticketObject.to[i] = "Paris";
						break;
					case 4:
						Flight_ticketObject.to[i] = "Moscow";
						break;
					case 5:
						Flight_ticketObject.to[i] = "Tokyo";
						break;
					case 6:
						Flight_ticketObject.to[i] = "New York";
						break;
					case 7:
						Flight_ticketObject.to[i] = "London";
						break;
					default:
						cout << "Invalid option";
						break;
					}
				} while (to_opt > 7);


				// Get the First Name
				cout << "Enter your first name : ";
				cin.ignore();
				//std::getline(std::cin, f_name[start_index++]);
				cin >> Flight_ticketObject.f_name[i];

				// Get the Last Name
				cout << "Enter your last name : ";
				cin.ignore();
				//std::getline(std::cin, l_name[end_index++]);
				cin >> Flight_ticketObject.l_name[i];


				//Get the date of ticket
				cout << "Date of flight : (DD-MM--YYYY) : ";
				cin.ignore();
				cin >> Flight_ticketObject.date[i];

				//Get the type of class
				do {
					cout << "\nTicket class:\n";
					cout << "1. Economy\n";
					cout << "2. Business\n";

					cout << "\nEnter your choice : ";
					cin >> class_opt;


					switch (class_opt) {
					case 1:
						Flight_ticketObject.t_class[i] = "Economy";
						book_class = "Economy";
						break;
					case 2:
						Flight_ticketObject.t_class[i] = "Business";
						book_class = "Business";
						break;
					default:
						cout << "Invalid option";
						break;
					}
				} while (class_opt > 2);

				//Get the payment option
				do {
					cout << "\nPayment Option:\n";
					cout << "1. Credit card\n";
					cout << "2. Debit card\n";
					cout << "3. Master card\n";

					cout << "\nEnter your choice : ";
					cin >> card_opt;


					switch (card_opt) {
					case 1:
						Flight_ticketObject.payment[i] = "Credit card";
						break;
					case 2:
						Flight_ticketObject.payment[i] = "Debit card";
						break;
					case 3:
						Flight_ticketObject.payment[i] = "Master card";
						break;
					default:
						cout << "Invalid option";
						break;
					}
				} while (card_opt > 3);


				if (book_class == "Economy") {
					Flight_ticketObject.fare_amt[i] = "680 $";
				}
				else {
					Flight_ticketObject.fare_amt[i] = "1200 $";
				}
			}
		}



		if (counter == 0) {
			cout << "\nTicket number not valid! Try again.\n";
		}
		else {
			cout << "\nTicket modified.\n";
			counter = 0;
		}
	}
};




int main()
{
	Showops ShowopsObject;
	Flight_ticket Flight_ticketObject;
	ViewTicket viewTicketObject;
	CancelTicket CancelTicketObject;
	ModifyTicket ModifyTicketObject;
	int choice;
	int dist[n], prev[n], dist1[n], prev1[n];
	int stack[n], stack1[n], k=0, d=0;
   Graph g(n);
   g.addEdge(0, 1, 300);
   g.addEdge(0, 2, 600);
   g.addEdge(1, 0, 300);
   g.addEdge(1, 2, 200);
   g.addEdge(1, 3, 100);
   g.addEdge(2, 0, 600);
   g.addEdge(2, 1, 200);
   g.addEdge(2, 3, 100);
   g.addEdge(2, 4, 400);
   g.addEdge(2, 5, 200);
   g.addEdge(3, 1, 100);
   g.addEdge(3, 2, 100);
   g.addEdge(3, 4, 200);
   g.addEdge(3, 6, 400);
   g.addEdge(4, 2, 400);
   g.addEdge(4, 3, 200);
   g.addEdge(4, 5, 200);
   g.addEdge(4, 6, 100);
   g.addEdge(5, 2, 200);
   g.addEdge(5, 4, 200);
   g.addEdge(5, 6, 100);
   g.addEdge(6, 3, 400);
   g.addEdge(6, 5, 100);
   g.addEdge(6, 4, 100);

    cout<<"########################\n";
    cout<<"\n\t1.Admin\n\n\t2.User\n\nEnter your choice: ";
    cin>>choice;
    if(choice == 2){
	    while (true){
	    
    		ShowopsObject.menu();
            cout<<"\n\n";
    		int opt;
    		cout << "\nEnter your option : ";
    		cin >> opt;
    
    		switch(opt) {
    		case 1:
    		    char source[20];
    		    int s;
    		    cout<<"\n----------------------------\n";
    		    cout<<"\n\nEnter source airport:";
    		    cin>>source;
    		    for(int j=0;j<7;j++){
    		        if(!(strcmp(arr[j],source))){
    		            s=j;
    		        }
    		    }
    		    dijkstra(g, dist, prev, s);
    		    cout<<"\n\nThe flight paths available from "<<source<<" are: \n";
    		    for(int i = 0; i<n; i++){
                    if(i != s){
                     cout<<arr[s]<<" to "<<arr[i]<<" // Distance: "<<dist[i]<<" // Previous city: "<<arr[prev[i]]<<endl<<endl;
                    }
                }
    			Flight_ticketObject.book();
    			cout << "\nYour ticket booked";
    			cout << "\nYour ticket number : " << book_no << "\n\n";
    			d=Flight_ticketObject.to_opt - 1;
				while(s!=d){
				for(int i = 0; i<n; i++){
                    if(i != s){
					 if(i==d){
						stack[k]=d;
						d=prev[i];
						k++;
					 }
                    }
                }
				}
				d=Flight_ticketObject.to_opt - 1;
				cout<<"\n\nYour connecting flights fo your trip from "<<arr[s]<<" to "<<arr[d]<<" are: ";
				cout<<"\n"<<arr[s];
				for(int i=k-1;i>=0;i--){
					cout<<" -> "<<arr[stack[i]];
				}
				cout<<"\n\n";
    			break;
    		case 2:
    			CancelTicketObject.cancelDetail(Flight_ticketObject);
    			break;
    		case 3:
    			viewTicketObject.viewDetail(Flight_ticketObject);
    			break;
    		case 4:
    			ModifyTicketObject.modifyTicket(Flight_ticketObject);
    			k=0;
    			s=ModifyTicketObject.src - 1;
    			d=ModifyTicketObject.des - 1;
    			dijkstra(g, dist1, prev1, s);
				while(s!=d){
				for(int i = 0; i<n; i++){
                    if(i != s){
					 if(i==d){
						stack1[k]=d;
						d=prev1[i];
						k++;
					 }
                    }
                }
				}
				d=ModifyTicketObject.des - 1;
				cout<<"\n\nYour connecting flights fo your trip from "<<arr[s]<<" to "<<arr[d]<<" are: ";
				cout<<"\n"<<arr[s];
				for(int i=k-1;i>=0;i--){
					cout<<" -> "<<arr[stack1[i]];
				}
				cout<<"\n\n";
    			break;
    		case 5:
    			exit(0);
    			break;
    		default:
    			cout << "\nInvalid option\n";
    			break;
    		}
	    }
    }
    else{
         while (true){
	    
    		ShowopsObject.menu();
            cout<<"\n6. Add a flight path\n\n";
    		int opt;
    		cout << "\nEnter your option : ";
    		cin >> opt;
    
    		switch(opt) {
    		
    		case 1:
    			Flight_ticketObject.book();
    			cout << "\nYour ticket booked";
    			cout << "\nYour ticket number : " << book_no << "\n\n";
    			break;
    		case 2:
    			CancelTicketObject.cancelDetail(Flight_ticketObject);
    			break;
    		case 3:
    			viewTicketObject.viewDetail(Flight_ticketObject);
    			break;
    		case 4:
    			ModifyTicketObject.modifyTicket(Flight_ticketObject);
    			break;
    		case 5:
    			exit(0);
    			break;
    		case 6:
    		    int o,p,d; 
    		    char a[20];
    		    char b[20];
    		    for (int j=0;j<7;j++){
    		        cout<<"\n"<<j+1<<"."<<arr[j];
    		    }
    		    cout<<"\nEnter a flight path between any two cities";
    		    cout<<"\nCity 1: ";
    		    cin>>a;
    		    cout<<"\nCity 2: ";
    		    cin>>b;
    		    for(int j=0;j<7;j++){
    		        if(!(strcmp(arr[j],a))){
    		            o=j;
    		        }
    		        if(!(strcmp(arr[j],b))){
    		            p=j;
    		        }
    		    }
    		    cout<<"\nEnter distance between them: ";
    		    cin>>d;
    		    g.addEdge(o,p,d);
    		    g.addEdge(p,o,d);
    		    g.displayEdges();
    		    break;
    		default:
    			cout << "\nInvalid option\n";
    			break;
    		}
	    }
    }

	system("PAUSE");
	return 0;
}
