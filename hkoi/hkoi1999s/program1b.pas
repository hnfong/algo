program program1;
type
	dom = record
		n  : array[1..2] of longint;
		v : boolean;
	end;
var
	gi : longint;
	c,d,e: longint;
	n : longint;
	a : array[1..15] of dom;

function maxval (x : longint; z : longint) : longint; { z is the unused part }
var
	i,j,k,t,u : longint;
begin
	a[x].v := true;
	writeln(a[x].n[1], ' ', a[x].n[2]);
	t := 0;
	for i := 1 to n do begin
		if a[i].v = false then begin
			if (a[x].n[z] = a[i].n[1]) then begin
				u := maxval(i, 2);
			end;
			if (a[x].n[z] = a[i].n[2]) then begin
				u := maxval(i, 1);
			end;
			if (u > t) then t:=u;
		end;
	end;
	t := t + a[x].n[1] + a[x].n[2];
	maxval := t;
	a[x].v := false;
end;

begin
	assign(input,'input1.txt');
	reset(input);
	readln(n);
	for gi := 1 to n do begin
		read(a[gi].n[1]);
		read(a[gi].n[2]);
		readln;
		a[gi].v := false;
	end;
	close(input);

	c := 0;
	d := 0;
	for gi := 1 to n do begin
		d := 0;
		d := maxval(gi, 1);
		writeln(d);
		if (d > c) then begin c := d; end;
		d := maxval(gi, 2);
		writeln(d);
		if (d > c) then begin c := d; end;
	end;
	writeln('final answer ', c);
end.

