program pstoh;
var
	i,j,k,n : longint;
	p : array[1..10] of longint;
procedure f(n,a,b:longint);
begin
	if a = b then begin
		if n > 1 then f(n-1,p[n-1],b);
		exit;
	end;
	if n = 1 then begin
		writeln(a-1,' ',b-1);
		p[n]:=b;
		exit;
	end;

	f(n-1,p[n-1],6-a-b);
	writeln(a-1,' ', b-1);
	p[n]:=b;
	f(n-1,6-a-b,b);
end;

begin
	readln(n);
	for i := 1 to n do begin
		readln(p[i]);
		inc(p[i]);
	end;
	f(n,p[n],p[n]);
end.
