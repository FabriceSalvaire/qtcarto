// -*- mode: c++ -*-

/***************************************************************************************************
**
** $QTCARTO_BEGIN_LICENSE:GPL3$
**
** Copyright (C) 2016 Fabrice Salvaire
** Contact: http://www.fabrice-salvaire.fr
**
** This file is part of the QtCarto library.
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
** $QTCARTO_END_LICENSE$
**
***************************************************************************************************/

/**************************************************************************************************/

#ifndef __WAYPOINT_H__
#define __WAYPOINT_H__

/**************************************************************************************************/

#include <QDateTime>
#include <QString>
#include <QList>

#include "coordinate/wgs84.h"

/**************************************************************************************************/

// QC_BEGIN_NAMESPACE

/**************************************************************************************************/

/*
 * wptType
 * <...
 * lat="latitudeType [1]"
 * lon="longitudeType [1]">
 * <ele> xsd:decimal </ele> [0..1]
 * <time> xsd:dateTime </time> [0..1]
 * <magvar> degreesType </magvar> [0..1]
 * <geoidheight> xsd:decimal </geoidheight> [0..1]
 * <name> xsd:string </name> [0..1]
 * <cmt> xsd:string </cmt> [0..1]
 * <desc> xsd:string </desc> [0..1]
 * <src> xsd:string </src> [0..1]
 * <link> linkType </link> [0..*]
 * <sym> xsd:string </sym> [0..1]
 * <type> xsd:string </type> [0..1]
 * <fix> fixType </fix> [0..1]
 * <sat> xsd:nonNegativeInteger </sat> [0..1]
 * <hdop> xsd:decimal </hdop> [0..1]
 * <vdop> xsd:decimal </vdop> [0..1]
 * <pdop> xsd:decimal </pdop> [0..1]
 * <ageofdgpsdata> xsd:decimal </ageofdgpsdata> [0..1]
 * <dgpsid> dgpsStationType </dgpsid> [0..1]
 * <extensions> extensionsType </extensions> [0..1]
 * </...>
 */

/**************************************************************************************************/

// Fixme: QcGpxWayPoint

class QC_EXPORT QcWayPoint
{
 public:
  QcWayPoint();
  QcWayPoint(const QcWayPoint & other);
  ~QcWayPoint();

  QcWayPoint & operator=(const QcWayPoint & other);

  // bool operator==(const QcWayPoint & rhs) const;

  // Elevation (in meters) of the point.
  QcWgsElevationCoordinate coordinate() const { return m_coordinate; }
  void set_coordinate(const QcWgsElevationCoordinate & coordinate) { m_coordinate = coordinate; }

  /* Creation/modification timestamp for element. Date and time in are
   * in Univeral Coordinated Time (UTC), not local time! Conforms to ISO
   * 8601 specification for date/time representation. Fractional seconds
   * are allowed for millisecond timing in tracklogs.
   */
  QDateTime time() const { return m_time; }
  void set_time(const QDateTime & time) { m_time = time; }

  // Magnetic variation (in degrees) at the point.
  qreal magnetic_variation() const { return m_magnetic_variation; }
  void set_magnetic_variation(qreal magnetic_variation) { m_magnetic_variation = magnetic_variation; }

  // Height (in meters) of geoid (mean sea level) above WGS84 earth
  // ellipsoid. As defined in NMEA GGA message.
  qreal geoid_height() const { return m_geoid_height; }
  void set_geoid_height(qreal geoid_height) { m_geoid_height = geoid_height; }

  /* The GPS name of the waypoint. This field will be transferred to
   * and from the GPS. GPX does not place restrictions on the length
   * of this field or the characters contained in it. It is up to the
   * receiving application to validate the field before sending it to
   * the GPS.
   */
  const QString & name() const { return m_name; }
  void set_name(const QString & name) { m_name = name; }

  // GPS waypoint comment. Sent to GPS as comment.
  const QString & comment() const { return m_comment; }
  void set_comment(const QString & comment) { m_comment = comment; }

  // A text description of the element. Holds additional information
  // about the element intended for the user, not the GPS.
  const QString & description() const { return m_description; }
  void set_description(const QString & description) { m_description = description; }

  // Source of data. Included to give user some idea of reliability and
  // accuracy of data. "Garmin eTrex", "USGS quad Boston North", e.g.
  const QString & source() const { return m_source; }
  void set_source(const QString & source) { m_source = source; }

  // Link to additional information about the waypoint.
  const QList<QString> link() const { return m_link; }
  void add_link(const QString & link) { m_link.append(link); }

  // Text of GPS symbol name. For interchange with other programs, use
  // the exact spelling of the symbol as displayed on the GPS. If the
  // GPS abbreviates words, spell them out.
  const QString & symbol() const { return m_symbol; }
  void set_symbol(const QString & symbol) { m_symbol = symbol; }

  // Type (classification) of the waypoint.
  const QString & type() const { return m_type; }
  void set_type(const QString & type) { m_type = type; }

  // Type of GPX fix.
  const QString & fix_type() const { return m_fix_type; }
  void set_fix_type(const QString & fix_type) { m_fix_type = fix_type; }

  // Number of satellites used to calculate the GPX fix.
  int number_of_satellites() const { return m_number_of_satellites; }
  void set_number_of_satellites(int number_of_satellites) { m_number_of_satellites = number_of_satellites; }

  // Horizontal dilution of precision.
  qreal hdop() const { return m_hdop; }
  void set_hdop(qreal hdop) { m_hdop = hdop; }

  // Vertical dilution of precision.
  qreal vdop() const { return m_vdop; }
  void set_vdop(qreal vdop) { m_vdop = vdop; }

  // Position dilution of precision.
  qreal pdop() const { return m_pdop; }
  void set_pdop(qreal pdop) { m_pdop = pdop; }

  // Number of seconds since last DGPS update.
  qreal age_of_dgps_data() const { return m_age_of_dgps_data; }
  void set_age_of_dgps_data(qreal age_of_dgps_data) { m_age_of_dgps_data = age_of_dgps_data; }

  // ID of DGPS station used in differential correction.
  int dgps_id() const { return m_dgps_id; }
  void set_dgps_id(int dgps_id) { m_dgps_id = dgps_id; }

 private:
  QcWgsElevationCoordinate m_coordinate;
  QDateTime m_time;
  qreal m_magnetic_variation;
  qreal m_geoid_height;
  QString m_name;
  QString m_comment;
  QString m_description;
  QString m_source;
  QList<QString> m_link;
  QString m_symbol;
  QString m_type;
  QString m_fix_type;
  int m_number_of_satellites;
  qreal m_hdop;
  qreal m_vdop;
  qreal m_pdop;
  qreal m_age_of_dgps_data;
  unsigned int m_dgps_id;
  // You can add extend GPX by adding your own elements from another schema here.
};

/**************************************************************************************************/

// QC_END_NAMESPACE

#endif /* __WAYPOINT_H__ */

/***************************************************************************************************
 *
 * End
 *
 **************************************************************************************************/
