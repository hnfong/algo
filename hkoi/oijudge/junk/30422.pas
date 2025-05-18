program p30422;
type
	co = record x,y : longint; end;
	board = array[1..5,1..5] of longint;
const
	dir : array[1..8,1..2] of longint = (
		(1,2),
		(1,-2),
		(2,1),
		(2,-1),
		(-1,2),
		(-1,-2),
		(-2,1),
		(-2,-1)
	);
	w : board = (
		(2,2,2,2,2),
		(1,2,2,2,2),
		(1,1,0,2,2),
		(1,1,1,1,2),
		(1,1,1,1,1)
	);
var
	e,i,j,k,n,lim : longint;
	t : board;
	spc : co;
	c : char;
procedure sw(x1,y1,x2,y2:longint);
var t : longint;
begin
	t := w[x1,y1];
	w[x1,y1] := w[x2,y2];
	w[x2,y2] := t;
	spc.x := x1;
	spc.y := y1;
end;
procedure dump;
begin
	for i := 1 to 5 do begin
		for j := 1 to 5 do begin
			write(w[i,j], ' ');
		end;write(' ');
		for j := 1 to 5 do begin
			write(t[i,j], ' ');
		end;
		writeln;
	end;
	writeln;
end;

function same : boolean;
var i,j : longint;
begin
	same := true;
	for i := 1 to 5 do begin
		for j := 1 to 5 do begin
			if w[i,j] <> t[i,j] then begin
				same := false;
				exit;
			end;
		end;
	end;
end;
procedure dfs(x1,y1,l : longint);
label hell;
var	i : longint;
	tmp : co;
begin
	{writeln(x1,' ',y1,' ',l);
	writeln(spc.x,spc.y);}
	tmp := spc;
	sw(x1,y1,tmp.x,tmp.y);
	if (l < lim) and same then begin
		lim := l;
		goto hell;
	end;
	if l < lim then 
		for i := 1 to 8 do begin
			if (x1+dir[i,1] <=5) and (y1+dir[i,2] <= 5) and (x1+dir[i,1] > 0) and (y1+dir[i,2] > 0) then begin
				dfs(x1+dir[i,1],y1+dir[i,2],l+1);
			end;
		end;
	hell:
	sw(tmp.x,tmp.y,x1,y1);
end;

begin
	lim := 20;
	for i := 1 to 5 do begin
		for j := 1 to 5 do begin 
			read(c);
			if c = '1' then t[i,j] := 2;
			if c = '0' then t[i,j] := 1;
			if c = ' ' then t[i,j] := 0;
		end;
		readln;
	end;
	spc.x := 3;
	spc.y := 3;
	if same then begin
		writeln(0);
		exit;
	end;
	for i := 1 to 8 do begin
		if (3+dir[i,1] > 0) and (3+dir[i,2] > 0) then begin
			dfs(3+dir[i,1],3+dir[i,2],1);
		end;
	end;
	writeln(lim);
end.
