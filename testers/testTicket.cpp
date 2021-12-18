#include "../source/objects/ticket.h"
#include "../source/manager/ticketManager.h"


int main() {
    ticketMananger manageTicket;
    ifstream fileT("./input/ticket.txt");
    manageTicket.read(fileT);
    manageTicket.show();
}
