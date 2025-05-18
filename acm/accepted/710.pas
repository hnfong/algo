program p710;
{
	@JUDGE_ID: 20044WC 710 PASCAL
}
type
	dat = record
		r,c,d : longint;
	end;
var
	i,j,k,n,ni,pairnum,w,h : longint;
	c1,r1,c2,r2 : longint;
	qh,qt : longint;
	q : array[1..6400] of dat;
	map : array[0..76,0..76] of char;
	u : array[0..76,0..76] of boolean;
	t : dat;
procedure push(c,r,d:longint);
begin
	if map[r][c] = 'X' then exit;
	if u[r][c] then exit;
	u[r][c] := true;
	inc(qh);
	q[qh].r := r;
	q[qh].c := c;
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
		readln(w,h);
		fillchar(map,sizeof(map),0);
		if (w=0) then break;
		for i := 1 to h do begin
			for j:= 1 to w do begin
				read(map[i,j]);
			end; readln;
		end;
		writeln('Board #',ni,':');
		pairnum := 0;
		while true do begin
			inc(pairnum);
			fillchar(u,sizeof(u),0);
			qh := 0;
			qt := 0;
			readln(c1,r1,c2,r2);
			if (c1=0) then break;
			map[r1][c1] := ' ';
			map[r2][c2] := ' ';
			push(c1,r1,0);
			while qh <> qt do begin
				t := pop;
				if (t.c = c2) and (t.r = r2) then break;
				for i := t.c+1 to w+1 do begin
					if map[t.r][i]='X' then break;
					push(i,t.r,t.d+1);
				end;
				for i := t.c-1 downto 0 do begin
					if map[t.r][i]='X' then break;
					push(i,t.r,t.d+1);
				end;
				for i := t.r+1 to h+1 do begin
					if map[i][t.c]='X' then break;
					push(t.c,i,t.d+1);
				end;
				for i := t.r-1 downto 0 do begin
					if map[i][t.c]='X' then break;
					push(t.c,i,t.d+1);
				end;
			end;
			if (t.c = c2) and (t.r = r2) then 
				writeln('Pair ',pairnum,': ',t.d,' segments.')
			else 
				writeln('Pair ',pairnum,': impossible.');
			map[r1][c1] := 'X';
			map[r2][c2] := 'X';
		end;
		writeln;
	end;
end.
