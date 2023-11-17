import Navbar from './Navbar';
import Footer from './Footer';
import Homepage from './Homepage';
function App() {
  
  return (
    <div className="App">
      <Navbar></Navbar>
      <div className="content">
      <Homepage></Homepage>
      </div>
      <Footer></Footer>
    </div>
  );
}

export default App;
