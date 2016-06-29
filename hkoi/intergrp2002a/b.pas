{ The dumb way of trying to solve the problem }
program intergroup2002a;
const hpas = 600 ; { the size of the array storing HPA data }
const base = 10; {can be set to powers of 10 for faster computation }
type hpa = record
	l : longint;
	a : array[1..hpas] of longint;
end;
var
	a,b,c,d : hpa;
	gi : longint;

{ empties/initializes the hpa variable to all zeros }
{ note: might be unnecessary for some situations, because of hpa.l }
procedure inithpa(var x : hpa);
var i : longint; {l prefix = local var} begin x.l := 0; for i := 1 to hpas do begin x.a[i] := 0; end; end;

{ dumps the hpa variable to screen  with a deliminator of string dlim}
procedure dumphpa(var x : hpa; dlim : string);
var i : longint; begin for i := x.l downto 1 do begin write(x.a[i]:3 , dlim); end; writeln; end;

procedure dumpallhpa(var x : hpa; dlim : string);
var i : longint; begin for i := hpas downto 1 do begin write(x.a[i], dlim); end; writeln; end;

{ add two hpa data types and returns the result (still a hpa) }
function addhpa(var x, y : hpa) : hpa;
var
	c,i,j,k,m: longint; { m = max length of x or y }
	t  : hpa; {temporary}
begin
	c := 0;
	if (x.l > y.l) then m := x.l else m := y.l;
	for i := 1 to m+1 do begin {m+1 for last carry}
		t.a[i] := x.a[i] + y.a[i] + c;
		c := t.a[i] div base;
		t.a[i] := t.a[i] mod base;
	end;
	addhpa := t;
end;

function int2hpa(q : longint) : hpa;
var i : longint; t : hpa; {temp}

begin
	i := 0;
	inithpa(t);
	while q > 0 do begin
		i := i + 1;
		t.a[i] := q mod base;
		q := q div base;
	end;
	t.l := i;
	int2hpa := t;
end;

function hpasqr(var x : hpa) : hpa;
var c,i,j,k : longint; t : hpa;
begin
	if (x.l * 2 - 1) > hpas then begin
		writeln('ERROR: Exceeded data size!!! in HPASQR');
		exit;
	end;
	c := 0;
	inithpa(t);
	for i := 1 to (x.l * 2 - 1) do begin
		t.a[i] := t.a[i] + c;
		for j := 1 to i do begin
			if (j > x.l) or ((i-j+1) > x.l) then continue; {could be optimized to be in the for loop counter range rather than here}
			t.a[i] := t.a[i] + x.a[j] * x.a[i-j+1];
		end;
		c := t.a[i] div base;
		t.a[i] := t.a[i] mod base;
	end;
	t.l := x.l * 2 - 1;
	hpasqr := t;
end;

function ismatch (var x,y : hpa) : boolean;
var
	i,j,k : longint;
begin
	if x.l <> y.l then begin ismatch := false; exit; end;
	if x.a[1] <> y.a[(y.l div 2) + (y.l mod 2)] then begin ismatch := false; exit; end;
	for i := 1 to (x.l div 2) do begin
		if y.a[i] <> x.a[i+1] then begin ismatch := false; exit; end;
	end;
	for i := x.l downto (y.l div 2) + (y.l mod 2) + 1 do begin
		if y.a[i] <> x.a[i] then begin ismatch := false; exit; end;
	end;
	writeln('ISMATCHALL ', gi);
end;

begin
	for gi := 100 to 11384563 do begin
		a:=int2hpa(gi);
		b:=int2hpa(gi+1);
		c:=hpasqr(a);
		d:=hpasqr(b);
{		writeln(gi,' ',gi+1);}
{		dumphpa(c, ' ');
		dumphpa(d, ' ');}
		ismatch(c,d);
	end;
end.

