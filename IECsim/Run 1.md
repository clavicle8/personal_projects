<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>IBSimu Run Log — Run 1</title>
<style>
  @import url('https://fonts.googleapis.com/css2?family=JetBrains+Mono:wght@400;600&family=Space+Grotesk:wght@300;400;600;700&display=swap');
 
  :root {
    --bg: #0d0f14;
    --surface: #13161d;
    --border: #1e2330;
    --accent: #4fc3f7;
    --accent2: #81d4fa;
    --warn: #ffb74d;
    --error: #ef5350;
    --success: #66bb6a;
    --muted: #4a5568;
    --text: #e2e8f0;
    --text-dim: #718096;
    --mono: 'JetBrains Mono', monospace;
    --sans: 'Space Grotesk', sans-serif;
  }
 
  * { box-sizing: border-box; margin: 0; padding: 0; }
 
  body {
    background: var(--bg);
    color: var(--text);
    font-family: var(--sans);
    min-height: 100vh;
    padding: 2rem;
  }
 
  .page {
    max-width: 900px;
    margin: 0 auto;
  }
 
  /* Header */
  .run-header {
    border-left: 3px solid var(--accent);
    padding-left: 1.5rem;
    margin-bottom: 2.5rem;
  }
 
  .run-label {
    font-family: var(--mono);
    font-size: 0.7rem;
    color: var(--accent);
    letter-spacing: 0.15em;
    text-transform: uppercase;
    margin-bottom: 0.4rem;
  }
 
  .run-title {
    font-size: 1.8rem;
    font-weight: 700;
    color: var(--text);
    line-height: 1.2;
  }
 
  .run-date {
    font-size: 0.85rem;
    color: var(--text-dim);
    margin-top: 0.3rem;
  }
 
  /* Version banner */
  .version-banner {
    background: var(--surface);
    border: 1px solid var(--border);
    border-radius: 6px;
    padding: 0.6rem 1rem;
    font-family: var(--mono);
    font-size: 0.75rem;
    color: var(--text-dim);
    margin-bottom: 2rem;
    display: flex;
    align-items: center;
    gap: 0.5rem;
  }
 
  .version-banner::before {
    content: '▸';
    color: var(--accent);
  }
 
  /* Section */
  .section {
    margin-bottom: 1.5rem;
  }
 
  .section-header {
    display: flex;
    align-items: center;
    gap: 0.75rem;
    margin-bottom: 0.75rem;
  }
 
  .section-title {
    font-family: var(--mono);
    font-size: 0.7rem;
    letter-spacing: 0.12em;
    text-transform: uppercase;
    color: var(--accent);
  }
 
  .section-line {
    flex: 1;
    height: 1px;
    background: var(--border);
  }
 
  /* Log block */
  .log-block {
    background: var(--surface);
    border: 1px solid var(--border);
    border-radius: 6px;
    overflow: hidden;
  }
 
  .log-line {
    font-family: var(--mono);
    font-size: 0.78rem;
    padding: 0.3rem 1rem;
    line-height: 1.6;
    color: var(--text-dim);
    border-bottom: 1px solid #1a1d26;
  }
 
  .log-line:last-child { border-bottom: none; }
 
  .log-line.key {
    color: var(--text);
  }
 
  .log-line.warn {
    color: var(--warn);
    background: rgba(255, 183, 77, 0.05);
  }
 
  .log-line.header-line {
    background: #0f1219;
    color: var(--accent);
    padding: 0.4rem 1rem;
    font-weight: 600;
    letter-spacing: 0.05em;
  }
 
  .log-line .label {
    color: var(--text-dim);
    min-width: 200px;
    display: inline-block;
  }
 
  .log-line .val {
    color: var(--text);
  }
 
  .log-line .val.good { color: var(--success); }
  .log-line .val.bad { color: var(--error); }
  .log-line .val.neutral { color: var(--accent2); }
 
  /* Stats grid */
  .stats-grid {
    display: grid;
    grid-template-columns: repeat(3, 1fr);
    gap: 0.75rem;
    margin-bottom: 1.5rem;
  }
 
  .stat-card {
    background: var(--surface);
    border: 1px solid var(--border);
    border-radius: 6px;
    padding: 0.9rem 1rem;
  }
 
  .stat-label {
    font-family: var(--mono);
    font-size: 0.65rem;
    color: var(--text-dim);
    text-transform: uppercase;
    letter-spacing: 0.1em;
    margin-bottom: 0.3rem;
  }
 
  .stat-value {
    font-family: var(--mono);
    font-size: 1.3rem;
    font-weight: 600;
    color: var(--accent);
  }
 
  .stat-value.warn { color: var(--warn); }
  .stat-value.good { color: var(--success); }
 
  /* Boundary table */
  .boundary-table {
    width: 100%;
    border-collapse: collapse;
    font-family: var(--mono);
    font-size: 0.76rem;
  }
 
  .boundary-table th {
    background: #0f1219;
    color: var(--text-dim);
    text-align: left;
    padding: 0.5rem 1rem;
    font-weight: 600;
    letter-spacing: 0.05em;
    text-transform: uppercase;
    font-size: 0.65rem;
  }
 
  .boundary-table td {
    padding: 0.4rem 1rem;
    border-bottom: 1px solid var(--border);
    color: var(--text-dim);
  }
 
  .boundary-table tr:last-child td { border-bottom: none; }
 
  .boundary-table .current-bar {
    height: 4px;
    background: var(--border);
    border-radius: 2px;
    overflow: hidden;
    margin-top: 3px;
  }
 
  .boundary-table .current-fill {
    height: 100%;
    background: var(--accent);
    border-radius: 2px;
  }
 
  .boundary-table .zero { color: var(--muted); }
 
  /* Review section */
  .review-block {
    background: var(--surface);
    border: 1px solid var(--border);
    border-left: 3px solid var(--warn);
    border-radius: 6px;
    padding: 1rem 1.25rem;
  }
 
  .review-item {
    display: flex;
    gap: 0.75rem;
    align-items: flex-start;
    margin-bottom: 0.6rem;
    font-size: 0.88rem;
    line-height: 1.5;
  }
 
  .review-item:last-child { margin-bottom: 0; }
 
  .review-item .bullet {
    color: var(--warn);
    font-family: var(--mono);
    font-size: 0.8rem;
    margin-top: 2px;
    flex-shrink: 0;
  }
 
  .review-item.good .bullet { color: var(--success); }
 
  /* Time footer */
  .time-footer {
    margin-top: 2rem;
    padding-top: 1rem;
    border-top: 1px solid var(--border);
    display: flex;
    justify-content: space-between;
    font-family: var(--mono);
    font-size: 0.72rem;
    color: var(--text-dim);
  }
</style>
</head>
<body>
<div class="page">
 
  <div class="run-header">
    <div class="run-label">IBSimu Simulation Log</div>
    <div class="run-title">Run 1</div>
    <div class="run-date">Sunday 12 April 2026 &nbsp;·&nbsp; IEC Fusor — Tee Chamber, N₂ Ion Trajectories</div>
  </div>
 
  <div class="version-banner">
    Ion Beam Simulator 1.0.6dev (89c1280, Thu Oct 26 17:14:45 2023 +0300)
  </div>
 
  <!-- Geometry -->
  <div class="section">
    <div class="section-header">
      <span class="section-title">Geometry</span>
      <div class="section-line"></div>
    </div>
    <div class="log-block">
      <div class="log-line header-line">Constructing Geometry from stream</div>
      <div class="log-line warn">⚠ Warning: loading of STLSolid not implemented (×3)</div>
    </div>
  </div>
 
  <!-- Solver -->
  <div class="section">
    <div class="section-header">
      <span class="section-title">Poisson Solver</span>
      <div class="section-line"></div>
    </div>
    <div class="log-block">
      <div class="log-line header-line">BiCGSTAB-ILU0</div>
      <div class="log-line key"><span class="label">Degrees of freedom</span><span class="val neutral">16,957,183</span></div>
      <div class="log-line"><span class="label">imax</span><span class="val">10,000</span></div>
      <div class="log-line"><span class="label">eps</span><span class="val">0.0001</span></div>
      <div class="log-line key"><span class="label">Iterations</span><span class="val neutral">168</span></div>
      <div class="log-line key"><span class="label">Error estimate</span><span class="val good">9.63 × 10⁻⁵ ✓ converged</span></div>
      <div class="log-line"><span class="label">Wall time</span><span class="val">183.976 s</span></div>
    </div>
  </div>
 
  <!-- Particle stats -->
  <div class="section">
    <div class="section-header">
      <span class="section-title">Particle Histories</span>
      <div class="section-line"></div>
    </div>
 
    <div class="stats-grid">
      <div class="stat-card">
        <div class="stat-label">Total</div>
        <div class="stat-value">1,000</div>
      </div>
      <div class="stat-card">
        <div class="stat-label">Flown</div>
        <div class="stat-value good">984</div>
      </div>
      <div class="stat-card">
        <div class="stat-label">Step-count limited</div>
        <div class="stat-value warn">16</div>
      </div>
      <div class="stat-card">
        <div class="stat-label">Time limited</div>
        <div class="stat-value">0</div>
      </div>
      <div class="stat-card">
        <div class="stat-label">Bad definitions</div>
        <div class="stat-value good">0</div>
      </div>
      <div class="stat-card">
        <div class="stat-label">Ave steps / particle</div>
        <div class="stat-value">92.9</div>
      </div>
    </div>
 
    <!-- Boundary table -->
    <div class="log-block">
      <table class="boundary-table">
        <thead>
          <tr>
            <th>Boundary</th>
            <th>Description</th>
            <th>Current (A)</th>
            <th>Particles</th>
            <th>Distribution</th>
          </tr>
        </thead>
        <tbody>
          <tr>
            <td>1</td><td>Domain face</td><td>5.28 × 10⁻⁴</td><td>264</td>
            <td><div class="current-bar"><div class="current-fill" style="width:100%"></div></div></td>
          </tr>
          <tr>
            <td>2</td><td>Domain face</td><td>2.42 × 10⁻⁴</td><td>121</td>
            <td><div class="current-bar"><div class="current-fill" style="width:46%"></div></div></td>
          </tr>
          <tr>
            <td>3</td><td>Domain face</td><td>4.04 × 10⁻⁴</td><td>202</td>
            <td><div class="current-bar"><div class="current-fill" style="width:76%"></div></div></td>
          </tr>
          <tr>
            <td>4</td><td>Domain face</td><td>3.88 × 10⁻⁴</td><td>194</td>
            <td><div class="current-bar"><div class="current-fill" style="width:73%"></div></div></td>
          </tr>
          <tr>
            <td>5</td><td>Domain face</td><td>2.20 × 10⁻⁵</td><td>11</td>
            <td><div class="current-bar"><div class="current-fill" style="width:4%"></div></div></td>
          </tr>
          <tr>
            <td>6</td><td>Domain face</td><td>3.84 × 10⁻⁴</td><td>192</td>
            <td><div class="current-bar"><div class="current-fill" style="width:73%"></div></div></td>
          </tr>
          <tr>
            <td>7</td><td>Tee chamber</td><td class="zero">0</td><td class="zero">0</td>
            <td><div class="current-bar"></div></td>
          </tr>
          <tr>
            <td>8</td><td>Cathode grid</td><td class="zero">0</td><td class="zero">0</td>
            <td><div class="current-bar"></div></td>
          </tr>
          <tr>
            <td>9</td><td>Anode grid</td><td class="zero">0</td><td class="zero">0</td>
            <td><div class="current-bar"></div></td>
          </tr>
        </tbody>
      </table>
    </div>
  </div>
 
  <!-- Review -->
  <div class="section">
    <div class="section-header">
      <span class="section-title">Post-Run Review</span>
      <div class="section-line"></div>
    </div>
    <div class="review-block">
      <div class="review-item">
        <span class="bullet">✗</span>
        <span>Used wrong cathode potential polarity (+5000 V instead of −5000 V) — this repelled positive ions outward, sending all particles to the domain walls instead of focusing toward the cathode.</span>
      </div>
      <div class="review-item good">
        <span class="bullet">✓</span>
        <span>All other parameters correct. Solver converged cleanly in 168 iterations. Zero bad particle definitions.</span>
      </div>
    </div>
  </div>
 
  <div class="time-footer">
    <span>Total wall time: 185.78 s</span>
    <span>CPU time: 179.216 s</span>
  </div>
 
</div>
</body>
</html>
