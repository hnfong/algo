program p1040;
var
	i,j,k,n,t,a,b : longint;
	inord,postord,preord: array[1..200000] of longint;
	ipos,ppos : array[1..200000] of longint;
	p : longint;
procedure dq (x,e,f : longint);
label hell;
begin
	{writeln(x,' ', e, ' ', f);}
	{if x = 0 then exit;}
	if e > f then exit;
	if e=f then goto hell;
	if ppos[x]+1 <= n then dq(preord[ppos[x]+1],e,ipos[x]-1);
	if ppos[x]+ipos[x]-e+1 <= n then dq(preord[ppos[x]+ipos[x]-e+1], ipos[x]+1, f);
	hell:
	inc(p);
	postord[p] := x;
end;

begin
	p := 0;
	readln(n);
	for i := 1 to n do read(preord[i]); readln;
	for i := 1 to n do read(inord[i]); readln;
	for i := 1 to n do begin
		ipos[inord[i]] := i;
		ppos[preord[i]] := i;
	end;
	dq(preord[1],1,n);
	for i := 1 to n - 1 do begin
		write(postord[i], ' ');
	end; writeln(postord[n]);
end.
