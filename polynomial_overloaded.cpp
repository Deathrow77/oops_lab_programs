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

    Term* getPolynomial();
    void addNewterm(int, int);
    Polynomial operator+(Polynomial p2);
    Polynomial operator-(Polynomial p2);
    friend void operator<<(ostream& obj, Polynomial& p);
    friend void operator>>(istream& obj, Polynomial& p);
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

Term* Polynomial::getPolynomial() {
    return start;
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

void operator<<(ostream& obj, Polynomial& p) {
    Term* temp = p.start;
    while (temp) {
        if (temp->index == 0)
            cout << temp->coeff;
        else if (temp->index == 1 && temp->coeff == 1)
            cout << "x";
        else if (temp->index == 1 && temp->coeff == 1)
            cout << "-x";
        else if (temp->index == 1 && temp->coeff != 1 && temp->coeff != -1)
            cout << temp->coeff << "x";
        else if (temp->index != 1 && temp->coeff == 1)
            cout << "x^" << temp->index;
        else if (temp->index != 1 && temp->coeff == -1)
            cout << "-x^" << temp->index;
        else
            cout << temp->coeff << "x^" << temp->index;
        temp = temp->next;
        if (temp)
            cout << " + ";
    }
    cout << endl;
}

void operator>>(istream& obj, Polynomial& p) {
    int t;
    cout << "Enter the number of terms for the first polynomial: ";
    cin >> t;
    while(t--) {
        int c, i;
        cout << "Enter coefficient and index of the term: ";
        cin >> c >> i;
        p.addNewterm(c, i);
    };
}


Polynomial Polynomial::operator+(Polynomial p2) {
    Term* t1 = start;
    Term* t2 = p2.getPolynomial();
    Polynomial res;
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


Polynomial Polynomial::operator-(Polynomial p2) {
    Term* t1 = start;
    Term* t2 = p2.getPolynomial();
    Polynomial res;
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


main(void) {

    int ch, c, i, t;

    Polynomial p1, p2;

    cin >> p1;
    cout << endl << "Polynomial 1: ";
    cout << p1;
    cout << endl;

    cin >> p2;
    cout << endl << "Polynomial 2: ";
    cout << p2;
    cout << endl;

    Polynomial add = p1 + p2;
    cout << "Addition: ";
    cout << add;

    Polynomial sub = p1 - p2;
    cout << "Subtraction: ";
    cout << sub;
}