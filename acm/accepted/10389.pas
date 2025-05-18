program p10389;
{
	@JUDGE_ID: 20044WC 10389 PASCAL "DaP/Dyp"
}
type
mytype = record x,y,s : integer end;
qtype = record x:integer;v : single; end;
var
	i,j,k : integer;
	v : array[1..202,1..202] of single;
	w : array[1..202] of mytype;
	u : array[1..202] of boolean;
	d : array[1..202] of single;
	nt,ni,ns : integer;
	n : integer;
	a,b : integer;
	speed : single;
	ev : single;
	ei : integer;
const
	speedhigh = (40 / 3.6 * 60);
	speedlow = (10 / 3.6 * 60);
begin
	readln(nt);
	for ni := 1 to nt do begin
		readln;
		readln(w[1].x,w[1].y, w[2].x,w[2].y);
		w[1].s := -1; w[2].s := -2;
		
		n := 2;
		ns := 1;
		while not eoln do begin
			read(a,b);
			if (a=-1) then begin readln; inc(ns); continue; end;
			inc(n);
			w[n].x := a; w[n].y := b;
			w[n].s := ns;
		end;
		
		for i := 1 to n do begin
			for j := i+1 to n do begin
				if (j-i = 1) and (w[i].s=w[j].s) then speed := speedhigh else speed := speedlow;
				v[i,j] := sqrt( (w[i].x-w[j].x)*(w[i].x-w[j].x) + (w[i].y-w[j].y)*(w[i].y-w[j].y) ) / speed;
				v[j,i] := v[i,j];
			end;
		end;

		if ni > 1 then writeln;

		fillchar(u,sizeof(u),0);
		for i := 2 to n do begin
			d[i] := 1E20;
		end;
		d[1] := 0;
		while true do begin
			ev := 1E20;
			ei := 0;
			for i := 1 to n do begin
				if u[i] = true then continue;
				if d[i] < ev then begin
					ei := i;
					ev := d[i];
				end;
			end;
			if ei = 2 then break;
			u[ei] := true;
			for i := 1 to n do begin
				if u[i] = false then begin
					if ev+v[ei,i] < d[i]  then begin
						d[i] := ev+v[ei,i];
					end;
				end;
			end;
		end;
		writeln(round(d[2]));
	end;
end.
