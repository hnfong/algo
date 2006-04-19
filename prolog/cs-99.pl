to(hongkong,taipei).
to(hongkong, sanfrancisco).
to(chicago, hongkong).
to(chicago, sanfrancisco).
to(sanfrancisco,delhi).
to(sanfrancisco,tokyo).
to(sanfrancisco,chicago).

oneleg(X,Y) :- to(X,Y).
twolegs(X, Z) :- oneleg(X,Y), oneleg(Y,Z).
threelegs(X,Z) :- oneleg(X,Y), twolegs(Y,Z).

