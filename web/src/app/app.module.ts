import { TurbineDataService } from './services/turbine-data.service';
import { CustomMaterialModule } from './material.module';
import { AppRoutingModule } from './app-routing.module';
import { SideBarComponent } from './components/side-bar/side-bar.component';
import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { NoopAnimationsModule, BrowserAnimationsModule } from '@angular/platform-browser/animations';

import { AppComponent } from './app.component';
import { TurbineDataComponent } from './components/turbine-data/turbine-data.component';
import { ChartComponent } from './components/chart/chart.component';
import { HistoricComponent } from './components/historic/historic.component';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';
import { AboutComponent } from './components/about/about.component';
import { HomeComponent } from './components/home/home.component';

import { HttpModule } from '@angular/http';

import { ComunicationApiService } from './services/comunication-api.service';

@NgModule({
  declarations: [
    AppComponent,
    TurbineDataComponent,
    SideBarComponent,
    ChartComponent,
    HistoricComponent,
    AboutComponent,
    HomeComponent
  ],
  imports: [
    AppRoutingModule,
    BrowserModule,
    BrowserAnimationsModule,
    CustomMaterialModule,
    NoopAnimationsModule,
    FormsModule,
    ReactiveFormsModule,
    HttpModule
  ],
  exports: [
  ],
  providers: [TurbineDataService, ComunicationApiService],
  bootstrap: [AppComponent]
})
export class AppModule { }
