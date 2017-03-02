// Halterung für einen Micromotor
// Kann direkt auf die Platine montiert werden
// 
// Ingo M. Schaefer, Februar 2017

fn = 48;
height = 8;

difference()
{
  union()
  {
	// Stabilisierung
    translate([0,-4.2,0]) difference() 
    {
      scale([1.1,1.5,1]) rotate([0,0,45]) cube([7,7,height], center=true);
      translate([0,-4,0]) cube([10,8,height+1], center=true);
    }
	// Der äußere Ring
    cylinder(h=height, r=9/2+1.2, center=true, $fn=fn);
  }

  // Innenteil (in der Form des Motors)
  difference() 
  {
    cylinder(h=height+1, r=9/2, center=true, $fn=fn);
    translate([0,5+7/2,0]) cube([10,10,height+1], center=true);
    translate([0,-5-7/2,0]) cube([10,10,height+1], center=true);
  }

  // Schlitz
  translate([0,5,0]) cube([3,5,height+1], center=true); 
}

// schräger Sockel mit Löchern für die Drähte
translate([0,-10.5,0])
difference()
{
  translate([0,1.4,0]) cube([11,10,height], center=true);
  translate([0,-6.7,-5]) rotate([35,0,0]) cube([12,20,20], center=true);
  translate([7.62/2,2.0,0]) rotate([-35,0,0]) cylinder(h=20, r=0.65, center=true, $fn=fn);
  translate([-7.62/2,2.0,0]) rotate([-35,0,0]) cylinder(h=20, r=0.65, center=true, $fn=fn);
}
