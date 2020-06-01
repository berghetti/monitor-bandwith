
/*
 *  Copyright (C) 2020 Mayco S. Berghetti
 *
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>

#include "sufix.h"

// sufixos RATE

// sufixos padrão IEC, com potências de 2, 1024, 2048..., com bytes
static const char *const sufix_iec_B[] = {"B/s",
                                          "KiB/s",
                                          "MiB/s",
                                          "GiB/s",
                                          "TiB/s"};

// sufixos padrão IEC com bits
// default
static const char *const sufix_iec_b[] = {"b/s",
                                          "Kib/s",
                                          "Mib/s",
                                          "Gib/s",
                                          "Tib/s"};

// sufixos padrão SI, com potências de 10. 1000, 2000..., com bytes
static const char *const sufix_si_B[] = {"B/s", "KB/s", "MB/s", "GB/s", "TB/s"};

// sufixos padrão SI com bits
static const char *const sufix_si_b[] = {"b/s", "Kb/s", "Mb/s", "Gb/s", "Tb/s"};

// sufixos total

// sufixos padrão IEC, com potências de 2, 1024, 2048..., com bytes
static const char *const sufix_iec_B_tot[] = {"B", "KiB", "MiB", "GiB", "TiB"};

// sufixos padrão IEC com bits
// default
static const char *const sufix_iec_b_tot[] = {"b", "Kib", "Mib", "Gib", "Tib"};

// sufixos padrão SI, com potências de 10. 1000, 2000..., com bytes
static const char *const sufix_si_B_tot[] = {"B", "KB", "MB", "GB", "TB"};

// sufixos padrão SI com bits
static const char *const sufix_si_b_tot[] = {"b", "Kb", "Mb", "Gb", "Tb"};

// defined in main.c
extern bool view_si;
extern bool view_bytes;

int chosen_base;
const char *const *sufix_rate;
const char *const *sufix_total;

void
define_sufix ( void )
{
  if ( view_si && view_bytes )
    {
      chosen_base = BASE_SI;
      sufix_rate = sufix_si_B;
      sufix_total = sufix_si_B_tot;
    }
  else if ( view_si )
    {
      chosen_base = BASE_SI;
      sufix_rate = sufix_si_b;
      sufix_total = sufix_si_b_tot;
    }
  else if ( view_bytes )
    {
      chosen_base = BASE_IEC;
      sufix_rate = sufix_iec_B;
      sufix_total = sufix_iec_B_tot;
    }
  else
    {  // default
      chosen_base = BASE_IEC;
      sufix_rate = sufix_iec_b;
      sufix_total = sufix_iec_b_tot;
    }
}
