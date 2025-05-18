{$R+,O+,Z+,M+}

program checkers01;
const yPos : array[1..121] of integer = (
                          00,
                        01, 01,
                      02, 02, 02,
                    03, 03, 03, 03,
  04, 04, 04, 04, 04, 04, 04, 04, 04, 04, 04, 04, 04,
    05, 05, 05, 05, 05, 05, 05, 05, 05, 05, 05, 05,
      06, 06, 06, 06, 06, 06, 06, 06, 06, 06, 06,
        07, 07, 07, 07, 07, 07, 07, 07, 07, 07,
          08, 08, 08, 08, 08, 08, 08, 08, 08,
        09, 09, 09, 09, 09, 09, 09, 09, 09, 09,
      10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
                    13, 13, 13, 13,
                      14, 14, 14,
                        15, 15,
                          16
);


const xPos : array[1..121] of integer = (
                             0,
                          -1, 1,
                         -2, 0, 2,
                       -3, -1, 1, 3,
  -12, -10, -8, -6, -4, -2,  0,  2,  4,  6,  8, 10, 12,
      -11, -9, -7, -5, -3, -1, 1, 3, 5, 7, 9, 11,
        -10, -8, -6, -4, -2, 0, 2, 4, 6, 8, 10,
           -9, -7, -5, -3, -1, 1, 3, 5, 7, 9,
             -8, -6, -4, -2, 0, 2, 4, 6, 8,
           -9, -7, -5, -3, -1, 1, 3, 5, 7, 9,
        -10, -8, -6, -4, -2, 0, 2, 4, 6, 8, 10,
      -11, -9, -7, -5, -3, -1, 1, 3, 5, 7, 9, 11,
   -12, -10, -8, -6, -4, -2, 0, 2, 4, 6, 8, 10, 12,
                      -3, -1, 1, 3,
                         -2, 0, 2,
                          -1, 1,
                            0
);

const LG = 0;
const MG = 1;
const DG = 2;
{
                        001
                      002 003
                    004 005 006
                  007 008 009 010
011 012 013 014 015 016 017 018 019 020 021 022 023
  024 025 026 027 028 029 030 031 032 033 034 035
    036 037 038 039 040 041 042 043 044 045 046
      047 048 049 050 051 052 053 054 055 056
        057 058 059 060 061 062 063 064 065
      066 067 068 069 070 071 072 073 074 075
    076 077 078 079 080 081 082 083 084 085 086
  087 088 089 090 091 092 093 094 095 096 097 098
099 100 101 102 103 104 105 106 107 108 109 110 111
                  112 113 114 115
                    116 117 118
                      119 120
                        121
}
const posColor : array[1..121] of integer = (
                          LG,
                        LG, LG,
                      LG, LG, LG,
                    LG, LG, LG, LG,
  DG, DG, DG, DG, MG, MG, MG, MG, MG, DG, DG, DG, DG,
    DG, DG, DG, MG, MG, MG, MG, MG, MG, DG, DG, DG,
      DG, DG, MG, MG, MG, MG, MG, MG, MG, DG, DG,
        DG, MG, MG, MG, MG, MG, MG, MG, MG, DG,
          MG, MG, MG, MG, MG, MG, MG, MG, MG,
        DG, MG, MG, MG, MG, MG, MG, MG, MG, DG,
      DG, DG, MG, MG, MG, MG, MG, MG, MG, DG, DG,
    DG, DG, DG, MG, MG, MG, MG, MG, MG, DG, DG, DG,
  DG, DG, DG, DG, MG, MG, MG, MG, MG, DG, DG, DG, DG,
                    LG, LG, LG, LG,
                      LG, LG, LG,
                        LG, LG,
                          LG
);

const hPosLeftCoord : array[1..17] of integer = ( 0, -1, -2, -3, -12, -11, -10, -9, -8, -9, -10, -11, -12, -3, -2, -1, 0);
const hPosRightCoord : array[1..17] of integer = ( 0, 1, 2, 3, 12, 11, 10, 9, 8, 9, 10, 11, 12, 3, 2, 1, 0);
const NumOnLines : array[1..17] of integer  =   ( 1, 2, 3, 4, 13, 12, 11, 10, 9, 10, 11, 12, 13, 4, 3, 2, 1);

var
	pos : array [1..2,1..10] of longint;
	fp  : text;
	i,j,k : longint;
	ret : array [1..6] of longint;
	q : longint;
	queue : array[1..100] of longint;
	map : array[1..121] of longint;

procedure clearq; begin q := 0; end;
function popq : longint; begin popq := queue[q]; q := q - 1; end;
procedure pushq (x : longint); begin q := q + 1; queue[q] := x; end;

function validate(f, t : longint) : boolean;
var
	i,j,k,d,ac : longint;
	b,s : longint; {b = bigger ; s = smaller }
begin
	writeln('validate: ', f, ' ', t);
	validate := false; {assume false}
	d := yPos[f] - yPos[t];
	if (d > 0) then begin
		b := f;
		s := t;
	end else begin
		b := t;
		s := f;
		d := -d;
	end;
	if (d mod 2 = 1) and (d > 1) then exit;
	if (d = 1) then begin
		if map[t] > 0 then validate := false else validate := true;
		exit;
	end;
	ac := 0;
	for i := s to b do begin
		ac := ac + NumOnLines[i];
		writeln('-> ', s+ac);
	end;
end;

begin
	assign(fp, 'input.txt');
	reset(fp);
	for j := 1 to 2 do begin
		for i := 1 to 10 do begin
			read(fp, pos[j][i]);
			map[pos[j][i]] := j;
		end;
		readln(fp);
	end;
	close(fp);

	for i := 1 to 10 do begin
		for j := 1 to 121 do begin
			if j = i then continue;
			if (yPos[j] + xPos[j]) = (yPos[i] + xPos[i]) then validate(i,j);
			if (yPos[j] - xPos[j]) = (yPos[i] - xPos[i]) then validate(i,j);
		end;
	end;
end.

