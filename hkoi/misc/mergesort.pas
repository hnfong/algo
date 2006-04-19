program ms;
{
	mergesort code
}
const n = 300000;
var
	a : array [1..n] of longint;
	b : array [1..n] of longint;
	gi : longint;

procedure dump; var i : longint; begin 	for i := 1 to n do write(a[i], ' ');writeln;end;

procedure merge(l,c,r : longint);
var
	p1 : longint;
	p2 : longint;
	x : longint;
	t1,t2 : longint;
begin
	p1 := l;
	p2 := c+1;
	x := l-1;

	while true do begin
		x := x + 1;
		t1 := a[p1];
		t2 := a[p2];
		if (p1 > c) then t1 := 0;
		if (p2 > r) then t2 := 0;
		if (p1 > c) and (p2 > r) then break;
		if (t1 > t2) then begin
			b[x] := t1;
			p1 := p1 + 1;
		end else begin
			b[x] := t2;
			p2 := p2 + 1;
		end;
	end;
	for x:=l to r do begin
		a[x] := b[x];
	end;
end;

procedure mergesort(l,r : longint);
var
	c : longint;
	x : longint;
begin
	if (l = r) then exit;
	if (l = r-1) then begin
		if (a[l] < a[r]) then begin
			x := a[l];
			a[l] := a[r];
			a[r] := x;
		end;
		exit;
	end;
	c := (l+r) div 2;
	mergesort(l,c);
	mergesort(c+1,r);
	merge(l,c,r);
end;
begin
	{gen rand}
	randomize;
	for gi := 1 to n do begin
		a[gi] := random(1000000) + 1;
	end;
	{dump;}

	mergesort (1,n);
	
	dump;
end.

