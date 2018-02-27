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
    void printPolynomial();
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

void Polynomial::printPolynomial() {
    Term* temp = start;
    while (temp) {
        if (temp->index == 0)
            cout << temp->coeff;
        else if (temp->index == 1 && temp->coeff == 1)
            cout << "x";
        else if (temp->index == 1 && temp->coeff != 1)
            cout << temp->coeff << "x";
        else if (temp->index != 1 && temp->coeff == 1)
            cout << "x^" << temp->index;
        else
            cout << temp->coeff << "x^" << temp->index;
        temp = temp->next;
        if (temp)
            cout << " + ";
    }
    cout << endl;
}


Polynomial addPolynomial(Polynomial p1, Polynomial p2) {
    Term* t1 = p1.getPolynomial();
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


main(void) {

    int ch, c, i, t;

    cout << "Enter the number of terms for the first polynomial: ";
    cin >> t;
    Polynomial p1;
    while(t--) {
        cout << "Enter coefficient and index of the term: ";
        cin >> c >> i;
        p1.addNewterm(c, i);
    };
    cout << endl << "Polynomial 1: ";
    p1.printPolynomial();
    cout << endl;

    cout << "Enter the number of terms for the second polynomial: ";
    cin >> t;
    Polynomial p2;
    while(t--) {
        cout << "Enter coefficient and index of the term: ";
        cin >> c >> i;
        p2.addNewterm(c, i);
    };
    cout << endl << "Polynomial 2: ";
    p2.printPolynomial();
    cout << endl;

    Polynomial res = addPolynomial(p1, p2);
    cout << "Addition: ";
    res.printPolynomial();
}