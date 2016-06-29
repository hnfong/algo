program p1041;
const inf = 2147483647;
var
	i,j,k,n,s,t : longint;
	a,b,c : longint;
	e,f : longint;
	w : array[1..1000,1..1000] of longint;
	d : array[1..1000] of longint;
	u : array[1..1000] of boolean;
	p : array[1..1000] of longint;
	written : boolean;
procedure swrite(x:longint);
begin
	if not written then write(x) else write(' ', x);
	written := true;
end;

procedure bt(x:longint);
begin
	if p[x] > 0 then bt(p[x]);
	swrite(x);
end;

begin
	for i := 1 to 1000 do d[i] := inf;
	for i := 1 to 1000 do 
		for j := 1 to 1000 do
			w[i,j] := inf;
	fillchar(u,sizeof(u),0);
	written := false;
	readln(n);
	readln(s,t);
	while true do begin
		readln(a,b,c);
		if (a=0) or (b=0) or (c=0) then break;
		w[a,b] := c;
		w[b,a] := c;
	end;
	d[s] := 0;
	p[s] := 0;
	while true do begin
		e := inf;
		for i := 1 to n do begin
			if (d[i] < e) and (not u[i]) then begin
				k := i;
				e := d[i];
			end;
		end;
		u[k] := true;
		if k = t then break;
		for i := 1 to n do begin
			if (w[k,i] <> inf) and (d[k] <> inf) and (d[k]+w[k,i]<d[i]) then begin
				d[i] := d[k]+w[k,i];
				p[i] := k;
			end;
		end;
	end;
	writeln(d[t]);
	bt(t);
	writeln;
end.
