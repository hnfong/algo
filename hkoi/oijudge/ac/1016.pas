program p1016;
const
	dir : array[1..2,1..2] of longint = (
		(0,1),
		(1,0)
	);
	g : array[1..2] of char = ('d','r');
var
	i,j,k,f : longint;
	w : array[1..9,1..9] of char;
	c : char;
procedure dump;
var i,j : longint;
begin
	for i := 1 to 9 do begin for j := 1 to 9 do write(w[j,i]); writeln; end; writeln;
end;

procedure swp(x1,y1, x2,y2 : longint);
var c : char;
begin
	if (x1<=0) or (y1<=0) or (x2<=0) or (y2<=0) then exit;
	if (x1>9) or (y1>9) or (x2>9) or (y2>9) then exit;
	c := w[x1,y1];
	w[x1,y1] := w[x2,y2];
	w[x2,y2] := c;
end;
function eval(x,y:longint) : longint;
var
	i,k : longint;
	nx,ny : longint;
begin
	nx := 0; ny := 0;
	i := 1;
	while (x-i>0)  do begin
		if w[x-i,y] = w[x,y] then inc(nx) else break;
		inc(i);
	end;
	
	i := 1;
	while (x+i<=9)  do begin
		if w[x+i,y] = w[x,y] then inc(nx) else break;
		inc(i);
	end;
	
	i := 1;
	while (y-i>0)  do begin
		if w[x,y-i] = w[x,y] then inc(ny) else break;
		inc(i);
	end;
	
	i := 1;
	while (y+i<=9)  do begin
		if w[x,y+i] = w[x,y] then inc(ny) else break;
		inc(i);
	end;
	k := 0;
	if (nx+1)>=3 then k := k + nx;
	if (ny+1)>=3 then k := k + ny;
	if k > 0 then eval := k+1 else eval := 0;
end;
function chk(x,y,d  : longint)  : longint;
var x1,x2,y1,y2 : longint;
begin
	x1 := x; y1 := y;
	x2 := x+dir[d,1];
	y2 := y+dir[d,2];
	swp(x1,y1,x2,y2);
	chk := eval(x1,y1) +  eval(x2,y2);
	swp(x2,y2,x1,y1);
end;

begin
	for i := 1 to 9 do begin
		for j := 1 to 9 do begin
			read(c);
			w[j,i] := c;
		end;
		readln;
	end;
	f := 0;
	for i := 1 to 9 do begin
		for j := 1 to 9 do begin
			for k := 1 to 2 do begin
				if (j=9) and (k=1) then continue;
				if (i=9) and (k=2) then continue;
				if chk(i,j,k)>f then begin f := chk(i,j,k); end;
			end;
		end;
	end;
	if f > 0 then writeln(5*power(3,f-3)) else begin
		writeln('No move');
		exit;
	end;
	for j := 1 to 9 do begin
		for i := 1 to 9 do begin
			for k := 1 to 2 do begin
				if (j=9) and (k=1) then continue;
				if (i=9) and (k=2) then continue;
				if chk(i,j,k)=f then begin 
					writeln('(',j,', ',i,') ', g[k]);
				end;
			end;
		end;
	end;
end.
