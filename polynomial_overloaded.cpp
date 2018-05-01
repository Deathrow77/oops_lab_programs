#include <bits/stdc++.h>

using namespace std;


typedef struct PolynomialNode {
    int coeff, index;
    struct PolynomialNode* next;
} Term;


class Polynomial {

    Term* start;
    Term* createNewTerm(int, int);

public:

    Polynomial() {
        start = NULL;
    }

    ~Polynomial() {
        while (start != NULL) {
            Term* temp = start;
            start = start->next;
            delete temp;
        }
    }

    Polynomial(Polynomial& other) {
        start = NULL;
        Term* temp = other.start;
        while (temp != NULL) {
            addNewterm(temp->coeff, temp->index);
            temp = temp->next;
        }
    }

    void addNewterm(int, int);
    Polynomial& operator=(Polynomial&);
    friend Polynomial& operator+(Polynomial&, Polynomial&);
    friend Polynomial& operator-(Polynomial&, Polynomial&);
    friend ostream& operator<<(ostream&, Polynomial&);
    friend istream& operator>>(istream&, Polynomial&);
};

Term* Polynomial::createNewTerm(int c, int i) {
    Term* newTerm = new Term;
    if (newTerm) {
        newTerm->coeff = c;
        newTerm->index = i;
        newTerm->next = NULL;
    }
    return newTerm;
}

void Polynomial::addNewterm(int c, int i) {
    Term* newTerm = createNewTerm(c, i);
    if (!newTerm) {
        cout << "A new term could not be added!" << endl;
        return;
    }

    // The polynomial is empty
    if (!start) {
        start = newTerm;
        return;
    }

    // New term will be added at the beginning of the polynomial
    if (i > start->index) {
        newTerm->next = start;
        start = newTerm;
    } else {
        Term* cur = start;
        Term* prev = NULL;
        bool mid = true;
        while (i < cur->index) {
            prev = cur;
            if (cur->next)
                cur = cur->next;
            // New term will be added at the end of the polynomial
            else {
                cur->next = newTerm;
                mid = false;
                break;
            }
        }
        // New term will be added in the middle of the polynomial
        if (mid) {
            prev->next = newTerm;
            newTerm->next = cur;
        }
    }
}

Polynomial& Polynomial::operator=(Polynomial& rhs) {
    start = NULL;
    Term* temp = rhs.start;
    while (temp != NULL) {
        addNewterm(temp->coeff, temp->index);
        temp = temp->next;
    }
    return *this;
}

ostream& operator<<(ostream& obj, Polynomial& p) {
    Term* temp = p.start;
    while (temp) {
        if (temp->index == 0)
            obj << temp->coeff;
        else if (temp->index == 1 && temp->coeff == 1)
            obj << "x";
        else if (temp->index == 1 && temp->coeff == -1)
            obj << "-x";
        else if (temp->index == 1 && temp->coeff != 1 && temp->coeff != -1)
            obj << temp->coeff << "x";
        else if (temp->index != 1 && temp->coeff == 1)
            obj << "x^" << temp->index;
        else if (temp->index != 1 && temp->coeff == -1)
            obj << "-x^" << temp->index;
        else
            obj << temp->coeff << "x^" << temp->index;
        temp = temp->next;
        if (temp)
            obj << " + ";
    }
    obj << endl;
    return obj;
}

istream& operator>>(istream& obj, Polynomial& p) {
    int t;
    cout << "Enter the number of terms for the polynomial: ";
    cin >> t;
    while(t--) {
        int c, i;
        cout << "Enter coefficient and index of the term: ";
        cin >> c >> i;
        p.addNewterm(c, i);
    };
    cout << endl;
    return obj;
}


Polynomial& operator+(Polynomial& p1, Polynomial& p2) {
    Term* t1 = p1.start;
    Term* t2 = p2.start;
    static Polynomial res;
    while (t1 && t2) {
        if (t1->index == t2->index) {
            res.addNewterm(t1->coeff + t2->coeff, t1->index);
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1->index > t2->index) {
            res.addNewterm(t1->coeff, t1->index);
            t1 = t1->next;
        } else {
            res.addNewterm(t2->coeff, t2->index);
            t2 = t2->next;
        }
    }
    while (t1) {
        res.addNewterm(t1->coeff, t1->index);
        t1 = t1->next;
    }
    while (t2) {
        res.addNewterm(t2->coeff, t2->index);
        t2 = t2->next;
    }
    return res;
}


Polynomial& operator-(Polynomial& p1, Polynomial& p2) {
    Term* t1 = p1.start;
    Term* t2 = p2.start;
    static Polynomial res;
    while (t1 && t2) {
        if (t1->index == t2->index) {
            res.addNewterm(t1->coeff - t2->coeff, t1->index);
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1->index > t2->index) {
            res.addNewterm(t1->coeff, t1->index);
            t1 = t1->next;
        } else {
            res.addNewterm(-t2->coeff, t2->index);
            t2 = t2->next;
        }
    }
    while (t1) {
        res.addNewterm(t1->coeff, t1->index);
        t1 = t1->next;
    }
    while (t2) {
        res.addNewterm(-t2->coeff, t2->index);
        t2 = t2->next;
    }
    return res;
}


int main(void) {

    Polynomial p1, p2;

    cin >> p1 >> p2;
    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;

    Polynomial add = p1 + p2;
    cout << "Addition: ";
    cout << add;

    Polynomial sub = p1 - p2;
    cout << "Subtraction: ";
    cout << sub;

    return 0;
}