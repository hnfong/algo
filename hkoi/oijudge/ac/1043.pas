program p1043;
const debug = false;
var
	i,k,n,l,x : longint;
	j : longint;
	w : array[0..10010] of longint;
procedure dump;
var i  : longint;
begin
	for i := 0 to n-1 do write(i:3) ; writeln;
	for i := 0 to n-1 do write(w[i]:3) ; writeln;
end;

function nexliv(x : longint) : longint;
var i,f : longint; t : longint;
begin
	f := (k-1) mod l;
	t := x;
	for i := 1 to f do begin
		t := w[t];
	end;
	nexliv := t;
end;

begin
	{ init }
	readln(n,k);
	for i := 0 to n-1 do begin
		w[i] := (i+1) mod n;
	end;
	j := n-1;
	l := n;
	for i := 1 to n-1 do begin
		j := nexliv(j);
		if debug then writeln('living', j);
		if debug then writeln('number alive:', l);
		x := w[j]; { find who to kill }
		if debug then writeln(x);
		w[j] := w[x]; { kill him ! }
		w[x] := -1;
		dec(l); { one less person on earth }
		if debug then dump;
	end;
	writeln(j);
end.
