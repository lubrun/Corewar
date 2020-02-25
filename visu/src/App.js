import React from 'react';
import './App.css';
import Header from './Components/js/Header'
import Body from './Components/js/Body';

function App() {
  return (
    <div className="App">
      <header className="App-header , center">
          <Header />
          <Body />
      </header>
    </div>
  );
}

export default App;
