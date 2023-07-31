/*
DISCLAIMER: this has not been peer reviewed. If you think there is a bug, please ask on piazza

In this document we will explore
* grammars
    * sentences in language defined by a grammar with LHD and parse trees
* judgment forms
    * Inference Rules
    * Judement Derivations
* Code
*/

/*
Consider this grammar for a singly linked list
    l ::= X | [ n, l ]
    n is a number
*/

/*
Consider the following LHDs demonstrating a few sentences that exist in the language:
* X
    * l -> X
* [5, X]
    * l -> [n, l] -> [5, l] -> [5, X]
        * OR skip-metavariables: l -> [5, l] -> [5, X]
* [7, [2, X]]
    * l -> [n, l] -> [7, l] -> [7, [n, l]] -> [7, [2, l]] -> [7, [2, X]]
        * OR skip-metavariables: l -> [7, l] -> [7, [2, l]] -> [7, [2, X]]
* NOTE: [7, 2, X] is not in the language as it is currently defined
* CHALLENGE: can you reimplement the grammar to write lists like that?

Can you draw parse trees for those sentences for this grammar?
YOUR_SOLUTION_HERE


X
>>>>>>>>>>>>>>>>>>
l
|
X
<<<<<<<<<<<<<<<<<<



[5, X]
>>>>>>>>>>>>>>>>>>
    l
    |
---------
| |    | | |
[ n(5) , l ]
<<<<<<<<<<<<<<<<<<



[7, [2, X]]
>>>>>>>>>>>>>>>>>>
    l
    |
---------
| |    | | |
[ n(7) , l ]
         |
     ----------
     | |    | | |
     [ n(2) , l ]
              |
              X
<<<<<<<<<<<<<<<<<<


Can you demonstrate that the following sentence exist in the langauge defined by the grammar?
With an LHD?
With a parse tree?
    * [10, [22, [4, X]]]
        *  YOUR_SOLUTION_HERE
        *  LHD: l -> [n, l] -> [10, l] -> [10, [n, l]] -> [10, [22, l]] -> [10, [22, [n, l]]] -> [10, [22, [4, l]]] -> [10, [22, [4, X]]]
            * OR skip-metavariables: l  -> [10, l] -> [10, [22, l]] -> [10, [22, [4, l]]] -> [10, [22, [4, X]]]
        * Parse tree not provided at this time, but post on piazza if you have it please!

*/

/*
Let this be a judment form: E(l) = n
* read: the E of some list l is a number n
* Don't wory about what E is at this time

Consider the following inference rules for this judgment:

--------- EEmpty
E(X) = 0


E(l') = n'    n'' = n + n'
------------------------- ENotEmpty
     E([n, l']) = n''

Consider this sample derivation for E([5, X]) = 5

-------- EEmpty
E(X) = 0          5 = 5 + 0
----------------------------- ENotEmpty
        E([5, X]) = 5

Can you derive E([7, [2, X]]) = 9?
YOUR_SOLUION_HERE
>>>>>>>>>>>>>>>>>

-------- EEmpty
E(X) = 0          2 = 2 + 0
----------------------------- ENotEmpty
        E([2, X]) = 2                       9 = 7 + 2
------------------------------------------------------ ENotEmpty
              E([7, [2, X]]) = 9
<<<<<<<<<<<<<<<<<
*/

/*
Now consider some valid code for the grammar
    l ::= X | [ n, l ]
    n is a number
*/
sealed abstract class MyList
case object MyX extends MyList  // X
case class MyNode(n: Int, l: MyList) extends MyList // [n, l]

/*
can you translate the inference rules to code?

--------- EEmpty
E(X) = 0


E(l') = n'    n'' = n + n'
------------------------- ENotEmpty
     E([n, l']) = n''

*/
def myE(l:MyList): Int = {
    // YOUR_SOLUION_HERE
    l match {
        case MyX => 0
        case MyNode(n, lp) => {
            val np = myE(lp)
            val npp = n + np
            npp
        }
    }
}
// E([5, X]) = 5
assert(0 == myE(MyX))
// E([7, [2, X]]) = 9
assert(9 == myE(MyNode(7, MyNode(2, MyX))))
"the myE tests pass"

/*
What is a better name for the myE function?
* YOUR_ANSWER_HERE
* sum or Sigma, but idk how to put it in code, so I used E 'cause they look kinda similar
*/


/*
Try another?

let f be a function from number to number as { ??? => ??? }

Let this be a judgment form: MyList foo f = MyList

Consider the folling inference rules

------------- FooEmpty
X foo f = X


f(n) = n'     l' foo f = l'''
--------------------------- FooNotEmpty
[n, l'] foo f = [n', l'']

*/

/*
Consider this sample Derivation for judgment  X foo {y => y + 1}  = X:

    -------------------------- FooEmpty
    X foo {y => y + 1}  = X


Consider this sample Derivation for judgment [7, [2, X]] foo {y => y + 1} = [8, [3, X]]:

                                                   ------------------------- FooEmpty
                          {y => y + 1}(2) = 3       X foo {y => y + 1} = X
                         -------------------------------------------------------------- FooNotEmpty
{y => y + 1}(7) = 8                     [2, X] foo {y => y + 1} = [3, X]
----------------------------------------------------------------------------------------------------- FooNotEmpty
                       [7, [2, X]] foo {y => y + 1} = [8, [3, X]]
*/

/*
Can you derive the judment [7, [2, X]] map {z => z * 2} = [14, [4, X]]
YOUR_SOLUION_HERE
>>>>>>>>>>>>>>>>>
                                                   ------------------------- FooEmpty
                          {z => z * 2}(2) = 4       X foo {z => z * 2} = X
                         -------------------------------------------------------------- FooNotEmpty
{z => z * 2}(7) = 14                     [2, X] foo {z => z * 2} = [4, X]
----------------------------------------------------------------------------------------------------- FooNotEmpty
                      [7, [2, X]] foo {z => z * 2} = [14, [4, X]]
<<<<<<<<<<<<<<<<<


What about the judment [22, [43, X]] map {a => 0} = [0, [0, X]]
YOUR_SOLUION_HERE
>>>>>>>>>>>>>>>>>
                                              ------------------------- FooEmpty
                          {a => 0}(43) = 4       X foo {a => 0} = X
                         ---------------------------------------------------------- FooNotEmpty
{a => 0}(22) = 0                     [43, X] foo {a => 0} = [0, X]
------------------------------------------------------------------------------------------------- FooNotEmpty
                      [22, [43, X]] foo {a => 0} = [0, [0, X]]
<<<<<<<<<<<<<<<<<
*/
/*
let f be a function from number to number

Let this be a judgment form: MyList foo f = MyList

Consider the folling inference rules

------------- FooEmpty
X foo f = X


f(n) = n'     l' foo f = l'''
--------------------------- FooNotEmpty
[n, l'] foo f = [n', l'']

can you code it?
*/
def myFoo(l: MyList)(f: Int => Int): MyList = {
    // YOUR_SOLUION_HERE
    l match {
        case MyX => MyX
        case MyNode(n, lp) => {
            val np = f(n)
            val lpp = myFoo(lp)(f)
            MyNode(np, lpp)
        }
    }
}    
// X foo {y => y + 1}  = X
def inc(x: Int): Int = x + 1
assert(MyX == myFoo(MyX)(inc))
assert(MyX == myFoo(MyX){ y => y + 1 })
assert(MyX == myFoo(MyX){ _ + 1 })
// [7, [2, X]] foo {y => y + 1} = [8, [3, X]]
assert(MyNode(8, MyNode(3, MyX)) == myFoo(MyNode(7, MyNode(2, MyX)))(inc))
assert(MyNode(8, MyNode(3, MyX)) == myFoo(MyNode(7, MyNode(2, MyX))){ y => y + 1 })
assert(MyNode(8, MyNode(3, MyX)) == myFoo(MyNode(7, MyNode(2, MyX))){ _ + 1 })
// [7, [2, X]] map {z => z * 2} = [14, [4, X]]
def dbl(x: Int): Int = x * 2
assert(MyNode(14, MyNode(4, MyX)) == myFoo(MyNode(7, MyNode(2, MyX)))(dbl))
assert(MyNode(14, MyNode(4, MyX)) == myFoo(MyNode(7, MyNode(2, MyX))){ z => z * 2 })
assert(MyNode(14, MyNode(4, MyX)) == myFoo(MyNode(7, MyNode(2, MyX))){ _ * 2 })
// [22, [43, X]] map {a => 0} = [0, [0, X]]
def zeroify(x: Int): Int = 0
assert(MyNode(0, MyNode(0, MyX)) == myFoo(MyNode(22, MyNode(42, MyX)))(zeroify))
assert(MyNode(0, MyNode(0, MyX)) == myFoo(MyNode(22, MyNode(42, MyX))){ a => 0 })
assert(MyNode(0, MyNode(0, MyX)) == myFoo(MyNode(22, MyNode(42, MyX))){ _ => 0 })
"the myFoo tests pass"

/*
What does the myFoo function actually do? Is there another name for this?
* YOUR_ANSWER_HERE
* map
*/

/*
Can you implement the above to return Options?
YOUR_SOLUTION_HERE
Answers not yet available, feel free to post your findings on piazza publically for feedback
*/


/*
Can you implement the flatMap, fold, filter or exists logic?
YOUR_SOLUTION_HERE
Answers not yet available, feel free to post your findings on piazza publically for feedback
*/

// BONUS: we could make those methods as follows:
sealed abstract class MyList2 {
    def map(f: Int => Int): MyList2 = this match {
        case MyX2 => MyX2
        case MyNode2(n, l) => MyNode2(f(n), l map f)
    }
    def foldRight[A](z: A)(f: (Int, A) => A): A = this match {
        case MyX2 => z
        case MyNode2(n, l) => f(n, l.foldRight(z)(f))
    }
    def foldLeft[A](z: A)(f: (A, Int) => A): A = this match {
        case MyX2 => z
        case MyNode2(n, l) => l.foldLeft(f(z, n))(f)
    }
    def sum = this.foldLeft(0){ _ + _ }
}
case object MyX2 extends MyList2  // X
case class MyNode2(n: Int, l: MyList2) extends MyList2 // [n, l]
assert(MyNode2(0, MyX2) == (MyNode2(22, MyX2) map { _ => 0 }))
assert(MyNode2(24, MyNode2(44, MyX2)) == (MyNode2(22, MyNode2(42, MyX2)) map { _ + 2 }))
assert(MyNode2(42, MyNode2(22, MyX2)) == (MyNode2(22, MyNode2(42, MyX2)).foldLeft(MyX2: MyList2){ (acc, h) => MyNode2(h, acc) }))
assert(MyNode2(24, MyNode2(44, MyX2)) == (MyNode2(22, MyNode2(42, MyX2)).foldRight(MyX2: MyList2){ (h, acc) => MyNode2(h+2, acc) }))
assert(64 == MyNode2(22, MyNode2(42, MyX2)).sum)


/*
Can you implement all of this for a Binary Tree as well?
* Grammar
    * Is it ambiguous?
* Sentences
    * LHD
    * ParseTree
* judgment form
    * inference rules
    * derivations
* class
* coded functions for the judgment forms
YOUR_SOLUTION_HERE
Answer not yet available, feel free to post your findings on piazza publically for feedback
*/

/*
Can you do it for a Tree of Lists and reuse existing code?
What about a List of Trees?
*/


/*
let us know if this helps and if you have ideas for another topic you'd like to have more practice with.
*/