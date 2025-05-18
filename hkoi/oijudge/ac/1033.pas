program p1033;
var
	i,j,k,n,s,ni : longint;
	c : char;
	w : array[1..1000] of longint;
function lpop : longint; begin lpop := w[s]; dec(s); end;
procedure lpush(x:longint); begin inc(s); w[s] := x; end;
function op(a,o,b:longint):longint;
begin
	if o = -2 then op := a+b;
	if o = -3 then op := a*b;
	if (a=0) and (b=0) and (o=-4) then begin op:=1; exit; end;
	if o = -4 then op := power(a,b);
end;

procedure dump; var i : longint; begin for i := 1 to s do write(w[i],' '); writeln; end;

procedure hpush(c : char);
var x,a,o,b : longint;
begin
	x := ord(c)-48;
	if c = 'z' then x := -1;
	if c = '+' then x := -2;
	if c = '*' then x := -3;
	if c = '^' then x := -4;
	if (x < 0) then begin
		while (s>=3) and ((w[s-1]<=x) and (x<>-4)) do begin
			b := lpop;
			o := lpop;
			a := lpop;
			lpush(op(a,o,b));
		end;
	end;
	lpush(x);
end;
begin
	readln(n);
	for ni := 1 to n do begin
		s := 0;
		while not eoln do begin
			read(c);
			hpush(c);
		end;readln;
		hpush('z');
		writeln(w[1]);
	end;
end.
