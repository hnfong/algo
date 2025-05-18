program sorts;
const
	siz = 1000000;
type
	data = array[1..siz] of longint;
var
	a : data;
	i,j,k : longint;
	n : longint;
	b : data;


{ insertion sort }
procedure isort(e,f,x:longint);
var
	i,j,k : longint;
begin
	for i := e to f do begin
		j := i;
		k := a[j];
		while (j-x >= e) and (a[j-x] > k) do begin
			a[j] := a[j-x];
			dec(j,x);
		end;
		a[j] := k;
	end;
end;

{ subroutine for mergesort - merge }
procedure merge(e,k,f: longint);
var
	i : longint;
	p1,p2,p3 : longint;
begin
	p3 := e;
	p1 := e;
	p2 := k+1;
	while (p1<=k) and (p2<=f) do begin
		if a[p1]<=a[p2] then begin
			b[p3] := a[p1];
			inc(p1);
		end else begin
			b[p3] := a[p2];
			inc(p2);
		end;
		inc(p3);
	end;
	while (p1<=k) do begin
		b[p3] := a[p1];
		inc(p3); inc(p1);
	end;
	while (p2<=f) do begin
		b[p3] := a[p2];
		inc(p3); inc(p2);
	end;
	for i := e to f do begin a[i] := b[i]; end;
end;

{ merge sort }
procedure msort(e,f:longint);
var k : longint;
begin
	if (e=f) then exit;
	if f-e <= 15 then begin
		isort(e,f,1);
		exit;
	end;
	k := (e+f) div 2;
	msort(e,k);
	msort(k+1,f);
	merge(e,k,f);
end;

{ modified counting sort for radix sort, capacity = 0..65535 (16 bits) }
{ x = how many 16 bits to shift right (s = (x-1)*16) }
procedure csort(e,f,x:longint;var a,b : data);
const
	m = 65535;
var
	c : array[0..65535] of longint;
	i,s : longint;
begin
	s := (x-1) * 16;
	fillchar(c,sizeof(c),0);
	for i := e to f do begin
		inc(c[(a[i] shr s) and m]);
	end;
	for i := 1 to 65535 do begin
		c[i] := c[i]+c[i-1];
	end;
	for i := f downto e do begin
		b[c[(a[i] shr s) and m]] := a[i];
		dec(c[(a[i] shr s) and m]);
	end;
end;

{ radix sort }
procedure rsort(e,f:longint);
begin
	csort(e,f,1,a,b);
	csort(e,f,2,b,a);
end;

{ dumb bubble sort }
procedure bsort(e,f:longint);
var
	i,j,k : longint;
begin
	for i := e to f do begin
		for j := i downto e+1 do begin
			if a[j] < a[j-1] then begin
				k := a[j];
				a[j] := a[j-1];
				a[j-1] := k;
			end else break;
		end;
	end;
end;


{ shell sort }
procedure ssort(e,f:longint);
var k : longint;
begin
	k := n;
	while k <> 1 do begin
		k := k div 3 + 1;
		isort(e,f,k);
	end;
end;

{ partitioning for Q sort }
{ random privot selection }
{ implementation slightly different from the books }
function partition(e,f:longint):longint;
var
	u,h,t : longint;
begin
	t := e+random(f-e);
	u := a[e];
	a[e] := a[t];
	a[t] := u;
	 
	t := f;
	h := e;
	while h <> t do begin
		if a[h] <= a[e] then begin
			inc(h); 
		end else begin
			u := a[t];
			a[t] := a[h];
			a[h] := u;
			dec(t);
		end;
	end;
	if a[h] > a[e] then dec(h);
	u := a[e];
	a[e]:=a[h];
	a[h] := u;
	partition := h;
end;

{ Quick Sort }
procedure qsort(e,f:longint);
var q : longint;
begin
	if f-e <= 0 then exit;
	if f-e <= 25 then begin
		isort(e,f,1);
		exit;
	end;
	q := partition(e,f);
	qsort(e,q-1);
	qsort(q+1,f);
end;

{ checking if the list is really sorted }
function check(e,f:longint) : boolean;
var i : longint;
begin
	check := true;
	for i := e to f - 1 do begin
		if a[i] > a[i+1] then check := false;
	end;
end;

begin
	randomize;
	{fillchar(a,sizeof(a),0);}
	{readln(n);}
	n := siz;
	for i := 1 to n do begin
		a[i] := random(n)+1;
	end;
	rsort(1,n);
	{for i := 1 to n do writeln(a[i]);}
	if not check(1,n) then writeln('!!!');
end.

