program p10477;
{
	@JUDGE_ID: 20044WC 10477 PASCAL
}
const
	hc : array[0..2,1..8,1..2] of longint = (
		((1,2),(1,-2),(-1,2),(-1,-2),(2,1),(2,-1),(-2,1),(-2,-1)),
		((1,3),(1,-3),(-1,3),(-1,-3),(3,1),(3,-1),(-3,1),(-3,-1)),
		((1,0),(-1,0),(0,1),(0,-1),(1,1),(-1,1),(1,-1),(-1,-1))
	);
type
	dat = record
		x,y,d,s  : longint;
	end;
var
	i,j,k,n,s,qh,qt,e,f,x1,y1,x2,y2,ni : longint;
	q : array[1..20*20*3] of dat;
	u : array[1..20,1..20,0..2] of boolean;
	t : dat;
procedure push(x,y,s,d:longint);
begin
	if (x<=0)or(y<=0)or(x>n)or(y>n) then exit;
	if u[x,y,s] then exit;
	u[x,y,s] := true;
	inc(qh);
	q[qh].x := x;
	q[qh].y := y;
	q[qh].s := s;
	q[qh].d := d;
end;
function pop : dat;
begin
	inc(qt);
	pop := q[qt];
end;
begin
	ni := 0;
	while true do begin
		inc(ni);
		readln(n,s);
		if (n = 0) then break;
		writeln('Set ',ni,':');
		while s > 0 do begin
			dec(s);
			readln(e,f);
			x1 := (e-1) mod n + 1;
			y1 := (e-1) div n + 1;
			x2 := (f-1) mod n + 1;
			y2 := (f-1) div n + 1;
			qh := 0; qt := 0;
			fillchar(u,sizeof(u),0);
			push(x1,y1,0,0);
			push(x1,y1,1,0);
			push(x1,y1,2,0);
			while (qh<>qt) do begin
				t := pop();
				if (t.x=x2) and (t.y=y2) then break;
				k := (t.s+1) mod 3;
				for i := 1 to 8 do begin
					if (k=2) and (i>4) then begin
						if (t.x+hc[k,i,1]=x2) and (t.y+hc[k,i,2]=y2) then
							push(t.x+hc[k,i,1], t.y+hc[k,i,2], k, t.d+1);
						continue;
					end;
					push(t.x+hc[k,i,1], t.y+hc[k,i,2], k, t.d+1)
				end;
			end;
			if (t.x=x2) and (t.y=y2) then writeln(t.d) else writeln('?');
		end;
	end;
end.

