/* TAG_RMI_CUSTOM_MAX_STREAM_FORMAT.java --
   Copyright (C) 2005 Free Software Foundation, Inc.

This file is part of GNU Classpath.

GNU Classpath is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU Classpath is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Classpath; see the file COPYING.  If not, write to the
Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
02110-1301 USA.

Linking this library statically or dynamically with other modules is
making a combined work based on this library.  Thus, the terms and
conditions of the GNU General Public License cover the whole
combination.

As a special exception, the copyright holders of this library give you
permission to link this library with independent modules to produce an
executable, regardless of the license terms of these independent
modules, and to copy and distribute the resulting executable under
terms of your choice, provided that you also meet, for each linked
independent module, the terms and conditions of the license of that
module.  An independent module is a module which is not derived from
or based on this library.  If you modify this library, you may extend
this exception to your version of the library, but you are not
obligated to do so.  If you do not wish to do so, delete this
exception statement from your version. */


package org.omg.IOP;

/**
 * A single constant interface, defining the
 * TAG_RMI_CUSTOM_MAX_STREAM_FORMAT (= 38) tagged component.
 *
 * This component defines the format that has been used to write the RMI-IIOP
 * value type objects in the message. It consists of the single byte,
 * having the value of the used version. If this component is missing,
 * the default value is assumed to be 1 for GIOP 1.2 and 2 for GIOP 1.3.
 * The component can occur only once in the same IOR profile.
 *
 * @since 1.5
 *
 * @author Audrius Meskauskas, Lithuania (AudriusA@Bioinformatics.org)
 */
public interface TAG_RMI_CUSTOM_MAX_STREAM_FORMAT
{
  /**
    * Specifies the TAG_RMI_CUSTOM_MAX_STREAM_FORMAT value, 38.
    */
  int value = 38;
}
