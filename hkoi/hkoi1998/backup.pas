program program1;
const
	max = 285;
type
	{ 1 = smallest }
	{ 100 = biggest }
	hpn = array[1..max] of byte;
var
	gi,gj,gk : longint;
	a : array[1..80,1..80] of hpn;
	z : array[1..80,1..80] of boolean;
	d : hpn;
	gx,gy,gz : longint;
	gw,gv : longint;
	one :hpn;
procedure zero(var d:hpn); var i : longint; begin gw:=gw+1;for i :=1 to max do d[i]:=0; end;
procedure dump(var d:hpn); var i : longint;
begin for i:=max downto 1 do write(d[i], ''); writeln; end;

function plus(var a,b : hpn) : hpn;
var
	i,m : longint;
	tmp : hpn;
begin
	gx := gx + 1;
	zero(tmp);
	for i:=max downto 1 do begin
		if (a[i] > 0) or (b[i] > 0) then begin m := i; break; end;
	end;
	for i:=1 to m do begin
		tmp[i] := tmp[i] + a[i] + b[i];
		tmp[i+1] := tmp[i] div 10;
		tmp[i] := tmp[i] mod 10;
	end;
	plus := tmp;
end;

procedure i2h(var t : hpn; x:longint; pow : longint); var i : integer;
begin
	gy := gy + 1;
	zero(t);
	i:=pow;
	while (x>0) do begin
		t[i] := x mod 10;
		x := x div 10;
		i := i + 1;
	end;
end;

procedure mul(var t:hpn; var a : hpn ; x : longint); 
var
	i : longint; t2 : hpn; t3: hpn;m : longint;
begin
	gv:=gv+1;
	zero(t);
	for i:=max downto 1 do begin
		if (a[i] > 0) then begin m := i; break; end;
	end;
	for i:=1 to m do begin
		i2h(t3, a[i] * x, i);
		t2 := plus(t3,t);
		t := t2;
	end;
end;

function func(x,y : longint) : hpn;
var
	t,t2,t3 : hpn;
begin
	if (x = 0) or (y =0) then begin
		func := one;
		exit;
	end;
	if (not z[x,y]) then begin
		func := a[x,y];
		exit;
	end;
	gz := gz + 1;
	{t := func(x-1,y)*y + func(x,y-1)*x;}

	t3 := func(x-1,y);
	mul(t, t3,y);
	t3 := func(x,y-1);
	mul(t2, t3,x);
	t := plus(t,t2);

	a[y,x] := t;
	z[y,x] := false;
	a[x,y] := t;
	z[x,y] := false;
	func := t;
	exit;
end;


{assume a}


begin
	for gi:=1 to 80 do
		for gj:=1 to 80 do begin
			zero(a[gi,gj]);
			z[gi,gj] := true;
		end;
	i2h(one, 1,1);
	zero(d);
	d := func(5,3);
	dump(d);
	writeln(gx, ' ', gy, ' ', gz);
	writeln(gw-80*80, ' ', gv, ' ', gz);
end.

