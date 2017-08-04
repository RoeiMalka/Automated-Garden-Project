name := """automated-garden"""
organization := "com.example"

version := "1.0-SNAPSHOT"

lazy val root = (project in file(".")).enablePlugins(PlayJava, PlayEbean)

scalaVersion := "2.12.2"

libraryDependencies ++= Seq(guice,
                            javaJdbc
)

libraryDependencies += "org.xerial" % "sqlite-jdbc" % "3.19.3" % "test"
