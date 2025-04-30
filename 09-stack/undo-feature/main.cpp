#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct Action {
    string type;
    string data;

    Action(string type, string data) {
        this->type=type;
        this->data=data;
    }
};

class TextEditor {
private:
    stack<Action> actions;

public:
    void performAction(const Action &action) {
        cout << "Performing action: " << action.type << " '" << action.data << "'\n";
        actions.push(action); 
    }

    void undoAction() {
        if(actions.empty()) {
            cout << "No actions to undo.\n";
            return;
        }

        Action action = actions.top();
        actions.pop();
        cout << "Undoing action: " << action.type << " '" << action.data << "'\n";
    }
};

int main() {
    TextEditor editor;

    editor.performAction(Action("add", "Hello"));
    editor.performAction(Action("add", "World"));
    editor.performAction(Action("delete", "World"));

    editor.undoAction(); // undo "delete" "World"
    editor.undoAction(); // undo "add" "World"
}