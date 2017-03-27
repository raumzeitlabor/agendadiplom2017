fn = 48;
wandstaerke = 1.4;
hoehe = 4;

difference()
{
  cylinder(r=6.5/2+wandstaerke, h=hoehe, center=true, $fn=fn);
  cylinder(r=6.5/2, h=hoehe+1, center=true, $fn=fn);
}

module abstandhalter()
{
  difference()
  {
    cylinder(r=6/2+wandstaerke, h=hoehe, center=true, $fn=fn);
    translate([-1.27,0,0]) cylinder(r=0.85, h=hoehe+1, center=true, $fn=fn);
    translate([+1.27,0,0]) cylinder(r=0.85, h=hoehe+1, center=true, $fn=fn);
    translate([0,0,1]) cylinder(r=6/2, h=hoehe, center=true, $fn=fn);
  }
}

translate([-7.62,0,0]) abstandhalter();
translate([+7.62,0,0]) abstandhalter();

