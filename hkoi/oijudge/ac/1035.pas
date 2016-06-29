program p1035;
type
	rec = record
		x,y : longint;
	end;
const
	hc : array[1..4,1..2] of integer = (
		(0,1),
		(1,0),
		(-1,0),
		(0,-1)
	);
var
	i,j,k,n,mx,my,h,x,y : longint;
	w : array[1..1000,1..1000] of longint;
	u : array[1..1000,1..1000] of boolean;
	q : array[1..1000000] of rec;
	qh,qt : longint;
	t : rec;
procedure dump; var i,j : longint; begin for i := 1 to my do begin for j := 1 to mx do write(w[j,i]:3); writeln; end; writeln;end;
procedure push(x,y,v : longint);
begin
	if (x<=0) or (y<=0) then exit;
	if (x>mx) or (y>my) then exit;
	if (u[x,y]) then exit;
	if (abs(w[x,y]-v) > h ) then exit;
	u[x,y] := true;
	inc(qt);
	q[qt].x := x;
	q[qt].y := y;
end;
function pop : rec;
begin
	inc(qh);
	pop := q[qh];
end;

begin
	fillchar(u,sizeof(u),0);
	readln(mx,my,h,x,y);
	for i := 1 to my do begin
		for j := 1 to mx do begin
			read(w[j,i]);
		end;readln;
	end;
	qh := 0; qt := 0;
	push(x,y, w[x,y]);
	while (qh<>qt) do begin
		t := pop;
		for i := 1 to 4  do begin
			push(t.x+hc[i,1],t.y+hc[i,2], w[t.x,t.y]);
		end;
	end;
	for i := 1 to my do begin
		for j:= 1 to mx do begin
			if u[j,i] then write(1) else write(0);
		end;
		writeln;
	end;
end.
